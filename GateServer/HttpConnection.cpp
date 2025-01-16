#include "HttpConnection.h"
#include "LogicSystem.h"

HttpConnection::HttpConnection(tcp::socket socket) : _socket(std::move(socket)) {
    // LOG_DEBUG("HttpConnection created for socket");
}
void HttpConnection::Start() {
    // LOG_DEBUG("HttpConnection::Start - Starting to handle connection");
    auto self = shared_from_this();
    http::async_read(
        _socket, _buffer, _request, [self](beast::error_code ec, std::size_t bytes_transferred) {
            try {
                if (ec) {
                    LOG_ERROR("HttpConnection::Start - Error reading data: %s",
                              ec.message().c_str());
                    std::cout << "http read error and errorno is : " << ec.message() << std::endl;
                    return;
                }
                //处理收到的消息
                LOG_DEBUG("HttpConnection::Start - Successfully read %zu bytes", bytes_transferred);
                boost::ignore_unused(bytes_transferred);
                self->HandleReq();
                self->CheckDeadline();
            } catch (std::exception &exp) {
                LOG_FATAL("HttpConnection::Start - Exception: %s", exp.what());
                std::cout << "exception is " << exp.what() << std::endl;
            }
        });
}
//socket没有拷贝构造，只有移动构造

void HttpConnection::HandleReq() {
    // LOG_DEBUG("HttpConnection::HandleReq - Handling request");
    _response.version(_request.version());
    //设置短链接
    _response.keep_alive(false);

    if (http::verb::get == _request.method()) {
        LOG_DEBUG("HttpConnection::HandleReq - Processing GET request");
        // bool success = LogicSystem::GetInstance()->HandleGet(_get_url, shared_from_this());
        bool success = LogicSystem::GetInstance()->HandleGet(_request.target().to_string(),
                                                             shared_from_this());
        if (!success) {
            LOG_ERROR("HttpConnection::HandleReq - URL not found:%s", _get_url.c_str());
            _response.result(beast::http::status::not_found);
            _response.set(beast::http::field::content_type, "text/plain");
            beast::ostream(_response.body()) << "url not found\r\n";
            WriteResponse();
            return;
        }
        LOG_DEBUG("HttpConnection::HandleReq - GET request processed successfully");
        _response.result(beast::http::status::ok);
        _response.set(beast::http::field::server, "GateServer");
        WriteResponse();
        return;
    }
}

//因为http是短链接，所以发送完数据后不需要再监听对方连接，之间断开发送端即可
void HttpConnection::WriteResponse() {
    // LOG_DEBUG("HttpConnection::WriteResponse - Sending response");
    auto self = shared_from_this();
    _response.content_length(_response.body().size());
    http::async_write(_socket, _response, [self](beast::error_code ec, std::size_t) {
        self->_socket.shutdown(tcp::socket::shutdown_send, ec);
        self->_deadline.cancel();
    });
}

void HttpConnection::CheckDeadline() {
    // LOG_DEBUG("HttpConnection::CheckDeadline - Checking deadline");
    auto self = shared_from_this();
    _deadline.async_wait([self](beast::error_code ec) {
        if (!ec) {
            //没出错就关了
            LOG_DEBUG("HttpConnection::CheckDeadline - Deadline reached, closing socket");
            self->_socket.close(ec);
        }
    });
}
