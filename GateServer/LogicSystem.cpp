//在cpp里include，防止互引用
#include "HttpConnection.h"
#include "LogicSystem.h"

void LogicSystem::RegGet(std::string url, HttpHandler handler) {
    // LOG_DEBUG("LogicSystem::RegGet - Registering GET handler for URL: %s", url.c_str());
    _get_handler.insert(make_pair(url, handler));
}

LogicSystem::LogicSystem() {
    RegGet("/get_test", [](std::shared_ptr<HttpConnection> connection) {
        LOG_DEBUG("LogicSystem::LogicSystem - Handling GET request for /get_test");
        beast::ostream(connection->_response.body()) << "receive get_test req";
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
