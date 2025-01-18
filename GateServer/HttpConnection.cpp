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
        PreParseGetParam();
        bool success = LogicSystem::GetInstance()->HandleGet(_get_url, shared_from_this());
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

    if (http::verb::post == _request.method()) {
        LOG_DEBUG("HttpConnection::HandleReq - Processing POST request");
        bool success = LogicSystem::GetInstance()->HandlePost(_request.target().to_string(),
                                                              shared_from_this());
        if (!success) {
            _response.result(http::status::not_found);
            _response.set(http::field::content_type, "text/plain");
            beast::ostream(_response.body()) << "url not found\r\n";
            WriteResponse();
            return;
        }
        LOG_DEBUG("HttpConnection::HandleReq - POST request processed successfully");
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

unsigned char ToHex(unsigned char x) {
    return x > 9 ? x + 55 : x + 48;
}

unsigned char FromHex(unsigned char x) {
    unsigned char y;
    if (x >= 'A' && x <= 'Z')
        y = x - 'A' + 10;
    else if (x >= 'a' && x <= 'z')
        y = x - 'a' + 10;
    else if (x >= '0' && x <= '9')
        y = x - '0';
    else
        assert(0);
    return y;
}

std::string UrlEncode(const std::string &str) {
    std::string strTemp = "";
    size_t length = str.length();
    for (size_t i = 0; i < length; i++) {
        //判断是否仅有数字和字母构成
        if (isalnum((unsigned char)str[i]) || (str[i] == '-') || (str[i] == '_') || (str[i] == '.')
            || (str[i] == '~'))
            strTemp += str[i];
        else if (str[i] == ' ') //为空字符
            strTemp += "+";
        else {
            //其他字符需要提前加%并且高四位和低四位分别转为16进制
            strTemp += '%';
            strTemp += ToHex((unsigned char)str[i] >> 4);
            strTemp += ToHex((unsigned char)str[i] & 0x0F);
        }
    }
    return strTemp;
}

std::string UrlDecode(const std::string &str) {
    std::string strTemp = "";
    size_t length = str.length();
    for (size_t i = 0; i < length; i++) {
        //还原+为空
        if (str[i] == '+')
            strTemp += ' ';
        //遇到%将后面的两个字符从16进制转为char再拼接
        else if (str[i] == '%') {
            assert(i + 2 < length);
            unsigned char high = FromHex((unsigned char)str[++i]);
            unsigned char low = FromHex((unsigned char)str[++i]);
            strTemp += high * 16 + low;
        } else
            strTemp += str[i];
    }
    return strTemp;
}

void HttpConnection::PreParseGetParam() {
    // 提取 URI
    auto uri = _request.target();
    // 查找查询字符串的开始位置（即 '?' 的位置）
    auto query_pos = uri.find('?');
    if (query_pos == std::string::npos) {
        _get_url = std::string(uri.data(), uri.size());
        return;
    }

    _get_url = std::string(uri.substr(0, query_pos).data(), uri.substr(0, query_pos).size());
    std::string query_string =
        std::string(uri.substr(query_pos + 1).data(), uri.substr(query_pos + 1).size());
    std::string key;
    std::string value;
    size_t pos = 0;
    while ((pos = query_string.find('&')) != std::string::npos) {
        auto pair = query_string.substr(0, pos);
        size_t eq_pos = pair.find('=');
        if (eq_pos != std::string::npos) {
            key = UrlDecode(pair.substr(0, eq_pos)); // 假设有 url_decode 函数来处理URL解码
            value = UrlDecode(pair.substr(eq_pos + 1));
            _get_params[key] = value;
        }
        query_string.erase(0, pos + 1);
    }
    // 处理最后一个参数对（如果没有 & 分隔符）
    if (!query_string.empty()) {
        size_t eq_pos = query_string.find('=');
        if (eq_pos != std::string::npos) {
            key = UrlDecode(query_string.substr(0, eq_pos));
            value = UrlDecode(query_string.substr(eq_pos + 1));
            _get_params[key] = value;
        }
    }
    LOG_INFO("PreParseGetParam url:%s", _get_url.c_str());
}
