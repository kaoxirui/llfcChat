#pragma once
#include "../common/log.h"
#include <atomic>
#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <boost/beast/http.hpp>
#include <boost/filesystem.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <functional>
#include <hiredis/hiredis.h>
#include <iostream>
#include <json/json.h>
#include <json/reader.h>
#include <json/value.h>
#include <map>
#include <memory>
#include <mutex>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

#define CODEPREFIX "code_"
#define USERIPPREFIX "uip_"
#define USERTOKENPREFIX "utoken_"
#define IPCOUNTPREFIX "ipcount_"
#define USER_BASE_INFO "ubaseinfo_"
#define LOGIN_COUNT "logincount"

namespace beast = boost::beast;   // from <boost/beast.hpp>
namespace http = beast::http;     // from <boost/beast/http.hpp>
namespace net = boost::asio;      // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp; // from <boost/asio/ip/tcp.hpp>

enum ErrorCodes {
    Success = 0,
    Error_Json = 1001,     //Json解析错误
    RPCFailed = 1002,      //RPC请求错误
    VarifyExpired = 1003,  //验证码过期
    VarifyCodeErr = 1004,  //验证码错误
    UserExist = 1005,      //用户已经存在
    PasswdErr = 1006,      //密码错误
    EmailNotMatch = 1007,  //邮箱不匹配
    PasswdUpFailed = 1008, //更新密码失败
    PasswdInvalid = 1009,  //密码更新失败
    TokenInvalid = 1010,   //Token失效
    UidInvalid = 1011,     //uid无效
};

class Defer {
public:
    Defer(std::function<void()> func) : _func(func) {}
    ~Defer() { _func(); }

private:
    std::function<void()> _func;
};