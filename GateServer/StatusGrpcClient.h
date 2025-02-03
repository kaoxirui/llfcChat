#pragma once

#include "const.h"
#include "message.grpc.pb.h"
#include "message.pb.h"
#include <grpcpp/grpcpp.h>
#include "Singleton.h"
using grpc::Channel;
using grpc::Status;
using grpc::ClientContext;

using message::GetChatServerReq;
using message::GetChatServerRsp;
using message::StatusService;

class StatusConnPool {
public:
    StatusConnPool(size_t pool_size, std::string host, std::string port);
    ~StatusConnPool();
    std::unique_ptr<message::StatusService::Stub> GetConnection();
    void ReturnConnection(std::unique_ptr<message::StatusService::Stub> context);
    void Close();

private:
    std::atomic<bool> _b_stop;
    size_t _pool_size;
    std::string _host;
    std::string _port;
    std::queue<std::unique_ptr<message::StatusService::Stub>> _grpc_conn_pool;
    std::mutex _mtx;
    std::condition_variable _cond;
};

class StatusGrpcClient : public Singleton<StatusGrpcClient> {
    friend class Singleton<StatusGrpcClient>;

public:
    ~StatusGrpcClient() {}
    message::GetChatServerRsp GetChatServer(int uid);

private:
    StatusGrpcClient();
    std::unique_ptr<StatusConnPool> _pool;
};