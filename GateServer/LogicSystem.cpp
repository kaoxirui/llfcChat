//在cpp里include，防止互引用
#include "HttpConnection.h"
#include "LogicSystem.h"
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
