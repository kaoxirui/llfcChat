#pragma once
#include "message.grpc.pb.h"
#include "message.pb.h"
#include <grpcpp/grpcpp.h>
#include "const.h"


using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using message::GetChatServerReq;
using message::GetChatServerRsp;
using message::StatusService;

//StatusServer路由到的具体聊天服务器，返回给客户端
class ChatServer {
public:
    ChatServer() : host(""), port(""), name(""), con_count(0) {}
    ChatServer(const ChatServer &cs)
        : host(cs.host), port(cs.port), name(cs.name), con_count(cs.con_count) {}
    ChatServer &operator=(const ChatServer &cs) {
        //const ChatServer &cs表示传入ChatServer对象，类型是const ChatServer&
        //this是当前对象的地址，是ChatServer*，即指向当前类类型的指针
        if (&cs == this) {
            //&cs是传入对象cs的地址，类型是const ChatSever*
            //对this解引用，表示当前对象本身，类型为ChatServer&
            //解引用表示从指针中获取所指向的对象
            return *this;
        }
        host = cs.host;
        name = cs.name;
        port = cs.port;
        con_count = cs.con_count;
        return *this;
    }
    std::string host;
    std::string port;
    std::string name;
    int con_count;
};

class StatusServiceImpl : public message::StatusService::Service {
public:
    StatusServiceImpl();
    grpc::Status GetChatServer(grpc::ServerContext *context,
                               const message::GetChatServerReq *request,
                               message::GetChatServerRsp *reply) override;
    grpc::Status Login(grpc::ServerContext *context, const message::LoginReq *request,
                       message::LoginRsp *reply) override;

private:
    void InsertToken(int uid, std::string token);
    ChatServer GetChatServer();

private:
    std::unordered_map<std::string, ChatServer> _servers;
    std::mutex _mtx;
};

extern std::string generate_unique_string()