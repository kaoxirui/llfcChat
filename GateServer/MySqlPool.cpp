#include "ConfigMgr.h"
#include "MySqlPool.h"
MySqlPool::MySqlPool(const std::string &url, const std::string &user, const std::string &pass,
                     const std::string &schema, int poolSize)
    : _url(url), _user(user), _pass(pass), _schema(schema), _pool_size(poolSize), _b_stop(false) {
    try {
        for (int i = 0; i < poolSize; i++) {
            sql::mysql::MySQL_Driver *driver = sql::mysql::get_mysql_driver_instance();
            auto *conn = driver->connect(_url, _user, _pass);
            conn->setSchema(_schema);
            //获取当前时间戳
            auto current_time = std::chrono::system_clock::now().time_since_epoch();
            auto time_stamp =
                std::chrono::duration_cast<std::chrono::seconds>(current_time).count();
            _sql_connection_pool.push(std::make_unique<sqlConnection>(conn, time_stamp));
        }
        //每60s检查连接池中的连接状态
        _check_thread = std::thread([this]() {
            while (!_b_stop) {
                CheckConnection();
                std::this_thread::sleep_for(std::chrono::seconds(60));
            }
        });
        _check_thread.detach();
    } catch (sql::SQLException &e) {
        LOG_ERROR("mysql pool init failed");
    }
}

std::unique_ptr<sqlConnection> MySqlPool::GetConnection() {
    std::unique_lock<std::mutex> lock(_mtx);
    _cond.wait(lock, [this]() {
        if (_b_stop) {
            return true;
        }
        return !_sql_connection_pool.empty();
    });
    if (_b_stop) {
        return nullptr;
    }
    std::unique_ptr<sqlConnection> conn(std::move(_sql_connection_pool.front()));
    _sql_connection_pool.pop();
    return conn;
}

void MySqlPool::ReturnConnection(std::unique_ptr<sqlConnection> con) {
    std::unique_lock<std::mutex> lock(_mtx);
    if (_b_stop) {
        return;
    }
    _sql_connection_pool.emplace(std::move(con));
    _cond.notify_one();
}

void MySqlPool::Close() {
    _b_stop = true;
    _cond.notify_all();
}

void MySqlPool::CheckConnection() {
    std::lock_guard<std::mutex> lock(_mtx);
    int pool_size = _sql_connection_pool.size();
    auto current_time = std::chrono::system_clock::now().time_since_epoch();
    auto time_stamp = std::chrono::duration_cast<std::chrono::seconds>(current_time).count();
    //遍历连接池
    for (int i = 0; i < pool_size; i++) {
        auto conn = std::move(_sql_connection_pool.front());
        _sql_connection_pool.pop();
        //使用Defer确保在操作完成后将连接放回池子
        //创建defer对象，在当前作用域结束时销毁（每次for循环迭代）
        Defer defer([this, &conn]() { _sql_connection_pool.push(std::move(conn)); });
        //连接的最后操作与当前时间差小于5s
        if (time_stamp - conn->_last_op_time < 5) {
            continue;
        }
        try {
            //查询连接是否有效
            std::unique_ptr<sql::Statement> stmt(conn->_conn->createStatement());
            stmt->executeQuery("SELECT 1");
            conn->_last_op_time = time_stamp;

        } catch (sql::SQLException &e) {
            LOG_INFO("Error keeping connection alive: "); // 重新创建连接
            sql::mysql::MySQL_Driver *driver = sql::mysql::get_mysql_driver_instance();
            auto *newconn = driver->connect(_url, _user, _pass);
            newconn->setSchema(_schema);
            conn->_conn.reset(newconn);
            conn->_last_op_time = time_stamp;
        }
    }
}

MySqlPool::~MySqlPool() {
    std::unique_lock<std::mutex> lock(_mtx);
    while (!_sql_connection_pool.empty()) {
        _sql_connection_pool.pop();
    }
}

MySqlDao::MySqlDao() {
    auto &config_mgr = ConfigMgr::Inst();
    const auto &host = config_mgr["MySql"]["host"];
    const auto &port = config_mgr["MySql"]["port"];
    const auto &pwd = config_mgr["MySql"]["passwd"];
    const auto &schema = config_mgr["MySql"]["schema"];
    const auto &user = config_mgr["MySql"]["user"];

    _pool.reset(new MySqlPool(host + ":" + port, user, pwd, schema, 5));
}

MySqlDao::~MySqlDao() {
    _pool->Close();
}

int MySqlDao::RegUser(const std::string &name, const std::string &email, const std::string &pwd) {
    auto conn = _pool->GetConnection();
    try {
        if (conn == nullptr) {
            return false;
        }
        // 准备调用存储过程reg_user,三个输入参数和一个输出参数（通过会话变量@result返回）
        std::unique_ptr<sql::PreparedStatement> stmt(
            conn->_conn->prepareStatement("CALL reg_user(?,?,?,@result)"));
        // 设置输入参数
        stmt->setString(1, name);
        stmt->setString(2, email);
        stmt->setString(3, pwd);
        // 由于PreparedStatement不直接支持注册输出参数，我们需要使用会话变量或其他方法来获取输出参数的值
        // 执行存储过程
        stmt->execute();
        // 如果存储过程设置了会话变量或有其他方式获取输出参数的值，你可以在这里执行SELECT查询来获取它们
        // 例如，如果存储过程设置了一个会话变量@result来存储输出结果，可以这样获取：
        std::unique_ptr<sql::Statement> stmtResult(conn->_conn->createStatement());
        std::unique_ptr<sql::ResultSet> res(stmtResult->executeQuery("SELECT @result AS result"));
        //解析查询结果
        if (res->next()) {
            int result = res->getInt("result");
            LOG_DEBUG("result:%d", result);
            _pool->ReturnConnection(std::move(conn));
            return result;
        }
        _pool->ReturnConnection(std::move(conn));
        return -1;
    } catch (sql::SQLException &e) {
        _pool->ReturnConnection(std::move(conn));
        LOG_ERROR("SQLException: %s", e.what());
        LOG_ERROR(" (MySQL error code: %d, SQLState:%s)", e.getErrorCode(),
                  e.getSQLState().c_str());
        return -1;
    }
}

bool MySqlDao::UpdatePwd(const std::string &name, const std::string &newpwd) {
    auto conn = _pool->GetConnection();
    try {
        if (conn == nullptr) {
            return false;
        }
        std::unique_ptr<sql::PreparedStatement> pstmt(
            conn->_conn->prepareStatement("UPDATE user SET pwd = ? WHERE name = ?"));
        pstmt->setString(2, name);
        pstmt->setString(1, newpwd);

        int updateCount = pstmt->executeUpdate();
        _pool->ReturnConnection(std::move(conn));
        return true;
    } catch (sql::SQLException &e) {
        _pool->ReturnConnection(std::move(conn));
        LOG_ERROR("SQLException: %s", e.what());
        LOG_ERROR(" (MySQL error code: %d, SQLState:%s)", e.getErrorCode(),
                  e.getSQLState().c_str());
        return false;
    }
}

bool MySqlDao::CheckEmail(const std::string &name, const std::string &email) {
    auto conn = _pool->GetConnection();
    try {
        if (conn == nullptr) {
            return false;
        }
        std::unique_ptr<sql::PreparedStatement> pstmt(
            conn->_conn->prepareStatement("SELECT email FROM user WHERE name = ?"));
        pstmt->setString(1, name);

        std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
        while (res->next()) {
            LOG_INFO("Check Email:%s", res->getString("email"));
            if (email != res->getString("email")) {
                _pool->ReturnConnection(std::move(conn));
                return false;
            }
            _pool->ReturnConnection(std::move(conn));
            return true;
        }
        return false;

    } catch (sql::SQLException &e) {
        _pool->ReturnConnection(std::move(conn));
        LOG_ERROR("SQLException: %s", e.what());
        LOG_ERROR(" (MySQL error code: %d, SQLState:%s)", e.getErrorCode(),
                  e.getSQLState().c_str());
        return false;
    }
}
bool MySqlDao::CheckPwd(const std::string &email, const std::string &pwd, UserInfo &userInfo) {
    auto conn = _pool->GetConnection();
    if (conn == nullptr) {
        return false;
    }
    Defer defer([this, &conn]() { _pool->ReturnConnection(std::move(conn)); });

    try {
        std::unique_ptr<sql::PreparedStatement> pstmt(
            conn->_conn->prepareStatement("SELECT * FROM user WHERE email = ?"));
        pstmt->setString(1, email);
        std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
        std::string origin_pwd = "";
        while (res->next()) {
            origin_pwd = res->getString("pwd");
            LOG_DEBUG("Password:%s", origin_pwd.c_str());
            break;
        }

        if (pwd != origin_pwd) {
            return false;
        }
        userInfo.name = res->getString("name");
        userInfo.email = res->getString("email");
        userInfo.uid = res->getInt("uid");
        userInfo.pwd = origin_pwd;
        return true;
    } catch (sql::SQLException &e) {
        LOG_ERROR("SQLException: %s", e.what());
        LOG_ERROR(" (MySQL error code: %d, SQLState:%s)", e.getErrorCode(),
                  e.getSQLState().c_str());
        return false;
    }
}
