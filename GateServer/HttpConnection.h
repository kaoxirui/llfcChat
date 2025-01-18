#pragma once
#include "const.h"

class HttpConnection : public std::enable_shared_from_this<HttpConnection> {
    friend class LogicSystem;

public:
    HttpConnection(tcp::socket socket);
    void Start();

private:
    //判断超时
    void CheckDeadline();
    void WriteResponse();
    void HandleReq();
    void PreParseGetParam();
    tcp::socket _socket;
    beast::flat_buffer _buffer{8192};
    http::request<http::dynamic_body> _request;
    http::response<http::dynamic_body> _response;
    //放在底层的事件循环里，一定要绑定io_contect
    net::steady_timer _deadline{_socket.get_executor(), std::chrono::seconds(60)};

    std::string _get_url;

    std::unordered_map<std::string, std::string> _get_params;
};
