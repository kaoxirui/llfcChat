#pragma once
#include "Singleton.h"
#include "const.h"
#include "message.grpc.pb.h"
#include <grpcpp/grpcpp.h>

using grpc::Channel;
using grpc::Status;
using grpc::ClientContext;

using message::GetVarifyReq;
using message::GetVarifyRsp;
using message::VarifyService;

class RPConPool {
public:
    RPConPool(std::size_t poolsize, std::string host, std::string port);
    ~RPConPool();
    void Close();
    std::unique_ptr<VarifyService::Stub> getConnection();
    void returnConnection(std::unique_ptr<VarifyService::Stub> context);

private:
    std::atomic<bool> _b_stop;
    std::size_t _pool_size;
    std::string _host;
    std::string _port;
    std::mutex _mtx;
    std::condition_variable _cond;
    std::queue<std::unique_ptr<VarifyService::Stub>> _connections;
};

class VarifyGrpcClient : public Singleton<VarifyGrpcClient> {
    friend class Singleton<VarifyGrpcClient>;

public:
    GetVarifyRsp GetVarifyCode(std::string email);

private:
    std::unique_ptr<RPConPool> _pool;
    VarifyGrpcClient();
    //信使
    //多个线程访问唯一一个stub，也会有危险
    // std::unique_ptr<VarifyService::Stub> stub_;
};