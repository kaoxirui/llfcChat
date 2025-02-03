//在cpp里include，防止互引用
#include "HttpConnection.h"
#include "LogicSystem.h"
#include "MySqlMgr.h"
#include "RedisMgr.h"
#include "StatusGrpcClient.h"
#include "VarifyGrpcClient.h"
void LogicSystem::RegGet(std::string url, HttpHandler handler) {
    // LOG_DEBUG("LogicSystem::RegGet - Registering GET handler for URL: %s", url.c_str());
    _get_handler.insert(make_pair(url, handler));
}

void LogicSystem::RegPost(std::string url, HttpHandler handler) {
    _post_handler.insert(make_pair(url, handler));
}

LogicSystem::LogicSystem() {
    RegGet("/get_test", [](std::shared_ptr<HttpConnection> connection) {
        LOG_DEBUG("LogicSystem::LogicSystem - Handling GET request for /get_test");
        beast::ostream(connection->_response.body()) << "receive get_test req";
        int i = 0;
        for (auto &elem : connection->_get_params) {
            i++;
            beast::ostream(connection->_response.body()) << "param" << i << "key is" << elem.first;
            beast::ostream(connection->_response.body()) << ","
                                                         << "value is" << elem.second;
        }
    });

    RegPost("/get_varifycode", [](std::shared_ptr<HttpConnection> connection) {
        auto body_str = boost::beast::buffers_to_string(connection->_request.body().data());
        LOG_DEBUG("received body is %s", body_str.c_str());
        connection->_response.set(http::field::content_type, "text/json");
        Json::Value root;
        Json::Reader reader;
        Json::Value src_root;
        bool prase_success = reader.parse(body_str, src_root);
        if (!prase_success) {
            LOG_ERROR("Failed to parse JSON data!");
            root["error"] = ErrorCodes::Error_Json;
            std::string jsonstr = root.toStyledString();
            beast::ostream(connection->_response.body()) << jsonstr;
            return true;
        }

        if (!src_root.isMember("email")) {
            LOG_DEBUG("failed to parese JSON data");
            root["error"] = ErrorCodes::Error_Json;
            std::string jsonstr = root.toStyledString();
            beast::ostream(connection->_response.body()) << jsonstr;
            return true;
        }

        auto email = src_root["email"].asString();
        GetVarifyRsp rsp = VarifyGrpcClient::GetInstance()->GetVarifyCode(email);
        LOG_DEBUG("email is %s", email.c_str());
        root["error"] = rsp.error();
        root["email"] = src_root["email"];
        std::string jsonstr = root.toStyledString();
        beast::ostream(connection->_response.body()) << jsonstr;
        return true;
    });
    RegPost("/user_register", [](std::shared_ptr<HttpConnection> connection) {
        // 将请求体缓冲区转换为字符串
        auto body_str = boost::beast::buffers_to_string(connection->_request.body().data());
        LOG_DEBUG("received body is %s", body_str.c_str());

        // 设置响应的内容类型为 JSON
        connection->_response.set(boost::beast::http::field::content_type, "text/json");

        Json::Value root;     // 用于构建响应 JSON
        Json::Value src_root; // 用于解析请求 JSON

        // 创建 CharReaderBuilder 和 CharReader
        Json::CharReaderBuilder readerBuilder;
        std::string errs;

        // 使用智能指针管理 CharReader 的生命周期
        std::unique_ptr<Json::CharReader> reader(readerBuilder.newCharReader());

        // 解析 JSON 字符串
        bool parse_success =
            reader->parse(body_str.c_str(), body_str.c_str() + body_str.size(), &src_root, &errs);

        if (!parse_success) {
            LOG_ERROR("Failed to parse JSON data!Error:%s", errs.c_str());
            root["error"] = ErrorCodes::Error_Json;
            // 将响应 JSON 转换为字符串
            std::string jsonstr = root.toStyledString();
            // 写入响应体
            boost::beast::ostream(connection->_response.body()) << jsonstr;
            return true;
        }

        std::string varify_code;
        bool b_get_varify =
            RedisMgr::GetInstance()->Get(CODEPREFIX + src_root["email"].asString(), varify_code);
        LOG_DEBUG("1");
        if (!b_get_varify) {
            LOG_INFO(" get varify code expired ");
            root["error"] = ErrorCodes::VarifyExpired;
            std::string jsonstr = root.toStyledString();
            beast::ostream(connection->_response.body()) << jsonstr;
            return true;
        }
        LOG_DEBUG("2");

        if (varify_code != src_root["varifycode"].asString()) {
            LOG_INFO(" varify code error");
            root["error"] = ErrorCodes::VarifyCodeErr;
            std::string jsonstr = root.toStyledString();
            beast::ostream(connection->_response.body()) << jsonstr;
            return true;
        }
        LOG_DEBUG("3");

        // 判断用户名在mysql中是否存在
        auto email = src_root["email"].asString();
        auto name = src_root["user"].asString();
        auto pwd = src_root["passwd"].asString();
        auto confirm = src_root["confirm"].asString();
        LOG_DEBUG("4");

        int uid = MySqlMgr::GetInstance()->RegUser(name, email, pwd);
        if (uid == 0 || uid == -1) {
            LOG_INFO("user or email exist:%d", uid);
            root["error"] = ErrorCodes::UserExist;
            std::string jsonstr = root.toStyledString();
            beast::ostream(connection->_response.body()) << jsonstr;
            return true;
        }
        LOG_DEBUG("5");

        root["error"] = 0;
        root["email"] = src_root["email"];
        root["user"] = src_root["user"].asString();
        root["passwd"] = src_root["passwd"].asString();
        root["confirm"] = src_root["confirm"].asString();
        root["varifycode"] = src_root["varifycode"].asString();
        std::string jsonstr = root.toStyledString();
        beast::ostream(connection->_response.body()) << jsonstr;
        return true;
    });

    RegPost("/reset_pwd", [](std::shared_ptr<HttpConnection> connection) {
        // 将请求体缓冲区转换为字符串
        auto body_str = boost::beast::buffers_to_string(connection->_request.body().data());
        LOG_INFO("receive body is ");

        // 设置响应的内容类型为 JSON
        connection->_response.set(boost::beast::http::field::content_type, "text/json");

        Json::Value root;     // 用于构建响应 JSON
        Json::Value src_root; // 用于解析请求 JSON

        // 创建 CharReaderBuilder 和 CharReader
        Json::CharReaderBuilder readerBuilder;
        std::string errs;

        // 使用智能指针管理 CharReader 的生命周期
        std::unique_ptr<Json::CharReader> reader(readerBuilder.newCharReader());

        // 解析 JSON 字符串
        bool parse_success =
            reader->parse(body_str.c_str(), body_str.c_str() + body_str.size(), &src_root, &errs);

        if (!parse_success) {
            LOG_INFO("Failed to parse JSON data! Error: %s", errs.c_str());
            root["error"] = ErrorCodes::Error_Json;
            // 将响应 JSON 转换为字符串
            std::string jsonstr = root.toStyledString();
            // 写入响应体
            boost::beast::ostream(connection->_response.body()) << jsonstr;
            return true;
        }

        std::string varify_code;
        bool b_get_varify =
            RedisMgr::GetInstance()->Get(CODEPREFIX + src_root["email"].asString(), varify_code);
        if (!b_get_varify) {
            LOG_INFO(" get varify code expired ");
            root["error"] = ErrorCodes::VarifyExpired;
            std::string jsonstr = root.toStyledString();
            beast::ostream(connection->_response.body()) << jsonstr;
            return true;
        }

        if (varify_code != src_root["varifycode"].asString()) {
            LOG_INFO(" varify code error");
            root["error"] = ErrorCodes::VarifyCodeErr;
            std::string jsonstr = root.toStyledString();
            beast::ostream(connection->_response.body()) << jsonstr;
            return true;
        }

        // 判断用户名在mysql中是否存在
        auto email = src_root["email"].asString();
        auto name = src_root["user"].asString();
        auto pwd = src_root["passwd"].asString();
        bool email_valid = MySqlMgr::GetInstance()->CheckEmail(name, email);
        if (!email_valid) {
            LOG_INFO(" user email not match");
            root["error"] = ErrorCodes::EmailNotMatch;
            std::string jsonstr = root.toStyledString();
            beast::ostream(connection->_response.body()) << jsonstr;
            return true;
        }

        bool b_up = MySqlMgr::GetInstance()->UpdatePwd(name, pwd);
        if (!b_up) {
            LOG_INFO(" update pwd failed");
            std::cout << " update pwd failed" << std::endl;
            root["error"] = ErrorCodes::PasswdUpFailed;
            std::string jsonstr = root.toStyledString();
            beast::ostream(connection->_response.body()) << jsonstr;
            return true;
        }

        LOG_INFO("succeed to update password");
        root["error"] = 0;
        root["email"] = email;
        root["user"] = name;
        root["passwd"] = pwd;
        root["varifycode"] = src_root["varifycode"].asString();
        std::string jsonstr = root.toStyledString();
        beast::ostream(connection->_response.body()) << jsonstr;
        return true;
    });
    RegPost("/user_login", [](std::shared_ptr<HttpConnection> connection) {
        auto body_str = boost::beast::buffers_to_string(connection->_request.body().data());
        LOG_INFO("receive body is ");
        // 设置响应的内容类型为 JSON
        connection->_response.set(boost::beast::http::field::content_type, "text/json");

        Json::Value root;     // 用于构建响应 JSON
        Json::Value src_root; // 用于解析请求 JSON

        // 创建 CharReaderBuilder 和 CharReader
        Json::CharReaderBuilder readerBuilder;
        std::string errs;

        // 使用智能指针管理 CharReader 的生命周期
        std::unique_ptr<Json::CharReader> reader(readerBuilder.newCharReader());

        // 解析 JSON 字符串
        bool parse_success =
            reader->parse(body_str.c_str(), body_str.c_str() + body_str.size(), &src_root, &errs);

        if (!parse_success) {
            LOG_INFO("Failed to parse JSON data! Error: %s", errs.c_str());
            root["error"] = ErrorCodes::Error_Json;
            // 将响应 JSON 转换为字符串
            std::string jsonstr = root.toStyledString();
            // 写入响应体
            boost::beast::ostream(connection->_response.body()) << jsonstr;
            return true;
        }
        auto email = src_root["email"].asString();
        auto pwd = src_root["passwd"].asString();
        UserInfo userInfo;
        // 查mysql看能否登陆
        bool pwd_valid = MySqlMgr::GetInstance()->CheckPwd(email, pwd, userInfo);
        if (!pwd_valid) {
            LOG_INFO(" user pwd not match");
            root["error"] = ErrorCodes::PasswdInvalid;
            std::string jsonstr = root.toStyledString();
            beast::ostream(connection->_response.body()) << jsonstr;
            return true;
        }

        //请求一个聊天服务器
        auto reply = StatusGrpcClient::GetInstance()->GetChatServer(userInfo.uid);
        if (reply.error()) {
            LOG_ERROR(" grpc get chat server failed, error is %d", reply.error());
            root["error"] = ErrorCodes::RPCFailed;
            std::string jsonstr = root.toStyledString();
            beast::ostream(connection->_response.body()) << jsonstr;
            return true;
        }
        // 写回发，给客户端，客户端根据回发信息与真正的聊天服务器建立长连接
        LOG_INFO("succeed to load userinfo uid is :%d", userInfo.uid);
        root["error"] = 0;
        root["email"] = email;
        root["uid"] = userInfo.uid;
        root["token"] = reply.token();
        root["host"] = reply.host();
        root["port"] = reply.port();
        std::string jsonstr = root.toStyledString();
        beast::ostream(connection->_response.body()) << jsonstr;
        return true;
    });
}

LogicSystem::~LogicSystem() {
    std::cout << "---------- LogicSystem::~LogicSystem ----------" << std::endl;
}

bool LogicSystem::HandleGet(std::string path, std::shared_ptr<HttpConnection> con) {
    if (_get_handler.find(path) == _get_handler.end()) {
        LOG_ERROR("LogicSystem::HandleGet - No handler found for path: %s", path.c_str());
        return false;
    }
    LOG_DEBUG("LogicSystem::HandleGet - Found handler for path: %s", path.c_str());
    _get_handler[path](con);
    return true;
}
bool LogicSystem::HandlePost(std::string path, std::shared_ptr<HttpConnection> con) {
    if (_post_handler.find(path) == _post_handler.end()) {
        LOG_ERROR("LogicSystem::HandlePost - No handler found for path: %s", path.c_str());
        return false;
    }
    LOG_DEBUG("LogicSystem::HandlePost - Found handler for path: %s", path.c_str());
    _post_handler[path](con);
    return true;
}
