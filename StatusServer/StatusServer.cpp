#include "../common/log.h"
#include "AsioIOServicePool.h"
#include "ConfigMgr.h"
#include "MySqlMgr.h"
#include "RedisMgr.h"
#include "StatusServiceImpl.h"
#include "const.h"
#include <boost/asio.hpp>
#include <hiredis/hiredis.h>
#include <iostream>
#include <json/json.h>
#include <json/reader.h>
#include <json/value.h>
#include <memory>
#include <string>
#include <thread>

void RunServer() {
    auto &config_mgr = ConfigMgr::GetInstance();
    std::string server_address =
        config_mgr["StatusServer"]["host"] + ":" + config_mgr["StatusServer"]["port"];
    StatusServiceImpl service;

    ::grpc::ServerBuilder builder;
    builder.AddListeningPort(server_address, ::grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    // 启动gRPCServer
    std::unique_ptr<::grpc::Server> server(builder.BuildAndStart());
    std::cout << "---------------- StatusServer start at:" << server_address << " ----------------"
              << std::endl;

    boost::asio::io_context io_context;
    boost::asio::signal_set signals(io_context, SIGINT, SIGTERM);

    // 异步等待结束
    signals.async_wait(
        [&server, &io_context](const boost::system::error_code &error, int signal_number) {
            if (!error) {
                std::cout << "Shutting down server ... ... " << std::endl;
                server->Shutdown();
                io_context.stop();
            }
        });

    std::thread([&io_context]() { io_context.run(); }).detach();

    // 等待
    server->Wait();
}

int main() {
    try {
        RunServer();
        RedisMgr::GetInstance()->Close();
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        RedisMgr::GetInstance()->Close();
        return -1;
    }

    return 0;
}
