#include "CServer.h"
#include "HttpConnection.h"
CServer::CServer(net::io_context &ioc, unsigned short &port)
    : _ioc(ioc), _acceptor(ioc, tcp::endpoint(tcp::v4(), port)), _socket(ioc) {
    LOG_INFO("CServer initialized, listening on port: %lu", port);
}

void CServer::Start() {
    auto self = shared_from_this(); //防止回调没回调过来，怕这个类被析构掉
    //传入self，回调函数没有调用之前，引用计数都是加1的
    _acceptor.async_accept(_socket, [self](beast::error_code ec) {
        try {
            //出错放弃这连接，继续监听其他连接
            if (ec) {
                LOG_ERROR("CServer::Start - Error accepting connection: %s", ec.message().c_str());
                self->Start();
                return;
            }
            //创建新连接，并且创建HttpConnection类管理这个连接
            LOG_INFO("CServer::Start - New connection accepted");
            std::make_shared<HttpConnection>(std::move(self->_socket))->Start();
            //继续监听
            self->Start();
        } catch (std::exception &exp) {
            LOG_FATAL("CServer::Start - Exception: %s", exp.what());
            std::cout << "exception is " << exp.what() << std::endl;
            self->Start();
        }
    });
}
