#pragma once
#include "const.h"
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mysql_connection.h>
#include <mysql_driver.h>

class sqlConnection {
public:
    sqlConnection(sql::Connection *conn, int64_t last_time)
        : _conn(conn), _last_op_time(last_time) {}
    std::unique_ptr<sql::Connection> _conn;
    int64_t _last_op_time;
};

struct UserInfo {
    std::string name;
    std::string pwd;
    int uid;
    std::string email;
};

class MySqlPool {
public:
    MySqlPool(const std::string &url, const std::string &user, const std::string &pass,
              const std::string &schema, int poolSize);
    std::unique_ptr<sqlConnection> GetConnection();
    void ReturnConnection(std::unique_ptr<sqlConnection> con);
    void Close();
    void CheckConnection();
    ~MySqlPool();

private:
    std::string _url;
    std::string _user;
    std::string _pass;
    std::string _schema;
    int _pool_size;
    std::queue<std::unique_ptr<sqlConnection>> _sql_connection_pool;
    std::mutex _mtx;
    std::condition_variable _cond;
    std::atomic<bool> _b_stop;
    std::thread _check_thread;
};

class MySqlDao {
public:
    MySqlDao();
    ~MySqlDao();
    int RegUser(const std::string &name, const std::string &email, const std::string &pwd);
    // int RegUserTransaction(const std::string &name, const std::string &email,
    //                        const std::string &pwd, const std::string &icon);
    bool CheckEmail(const std::string &name, const std::string &email);
    bool UpdatePwd(const std::string &name, const std::string &email);
    bool CheckPwd(const std::string &email, const std::string &pwd, UserInfo &userInfo);
    // bool TestProcedure(const std::string &email, int &uid, std::string &name);

private:
    std::unique_ptr<MySqlPool> _pool;
};