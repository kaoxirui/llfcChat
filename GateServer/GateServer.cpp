#include "CServer.h"
#include "ConfigMgr.h"
#include "HttpConnection.h"
#include "const.h"
int main() {
    //在构造时就可以把配置读出来
    auto  &gCfgMgr=ConfigMgr::Inst();
    std::string gate_port = gCfgMgr["GateServer"]["Port"];
    try {
        unsigned short port = atoi(gate_port.c_str());
        net::io_context ioc{1};
        boost::asio::signal_set signals(ioc, SIGINT, SIGTERM);
        signals.async_wait([&ioc](const boost::system::error_code &error, int signal_number) {
            if (error) {
                return;
            }
            ioc.stop();
        });
        std::make_shared<CServer>(ioc, port)->Start();
        ioc.run();
    } catch (std::exception const &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}