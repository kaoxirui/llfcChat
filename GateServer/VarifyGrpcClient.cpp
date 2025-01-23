#include "ConfigMgr.h"
#include "VarifyGrpcClient.h"
RPConPool::RPConPool(std::size_t poolsize, std::string host, std::string port)
    : _pool_size(poolsize), _host(host), _port(port), _b_stop(false) {
    for (std::size_t i = 0; i < _pool_size; i++) {
        std::shared_ptr<Channel> channel =
            grpc::CreateChannel(_host + ":" + port, grpc::InsecureChannelCredentials());
        //NewStub返回的是unique_ptr，push调用的移动构造
        _connections.push(VarifyService::NewStub(channel));
        // //uniqut_ptr不支持拷贝构造
        // auto m=VarifyService::NewStub(channel);
        // _connections.push(m);
    }
}

RPConPool::~RPConPool() {
    std::lock_guard<std::mutex> lock(_mtx);
    //回收池子时，也要告诉线程要关闭了
    Close();
    while (!_connections.empty()) {
        _connections.pop();
    }
}
void RPConPool::Close() {
    _b_stop = true;
    _cond.notify_all();
}

std::unique_ptr<VarifyService::Stub> RPConPool::getConnection() {
    std::unique_lock<std::mutex> lock(_mtx);
    _cond.wait(lock, [this] {
        if (_b_stop) {
            return true;
        }
        //wait
        //为空，返回false，lambda表达式返回false，线程挂起到等待的区域，并解锁，不会再往下走了
        //其他人notify，才继续加锁并往下走
        return !_connections.empty();
    });
    //走下来了有两种情况，true和false
    //如果停止则返回空指针
    if (_b_stop) {
        return nullptr;
    }
    //为false说明队列不为空
    auto context = std::move(_connections.front());
    _connections.pop();
    return context;
}

void RPConPool::returnConnection(std::unique_ptr<VarifyService::Stub> context) {
    std::lock_guard<std::mutex> lock(_mtx);
    //可能已经析构掉了
    if (_b_stop) {
        return;
    }
    _connections.push(std::move(context));
    _cond.notify_one();
}

VarifyGrpcClient::VarifyGrpcClient() {
    // //通道
    // std::shared_ptr<Channel> channel =
    //     grpc::CreateChannel("127.0.0.1:50051", grpc::InsecureChannelCredentials());
    // stub_ = VarifyService::NewStub(channel);
    auto &config_mgr = ConfigMgr::Inst();
    std::string host = config_mgr["VarifyServer"]["host"];
    std::string port = config_mgr["VarifyServer"]["port"];
    _pool.reset(new RPConPool(5, host, port));
}

GetVarifyRsp VarifyGrpcClient::GetVarifyCode(std::string email) {
    ClientContext context;
    GetVarifyRsp reply;
    GetVarifyReq request;

    request.set_email(email);
    auto stub = _pool->getConnection();
    Status status = stub->GetVarifyCode(&context, request, &reply);
    if (status.ok()) {
        _pool->returnConnection(std::move(stub));
        return reply;
    } else {
        _pool->returnConnection(std::move(stub));
        reply.set_error(ErrorCodes::RPCFailed);
        return reply;
    }
}