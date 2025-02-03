#include "ConfigMgr.h"
#include "RedisMgr.h"

RedisMgr::RedisMgr() {
    auto config_mgr = ConfigMgr::Inst();
    auto host = config_mgr["Redis"]["host"];
    auto port = config_mgr["Redis"]["port"];
    auto pwd = config_mgr["Redis"]["pwd"];
    //reset会释放当前管理对象，并将只能指针指向一个新的对象
    _con_pool.reset(new RedisConPool(5, host.c_str(), atoi(port.c_str()), pwd.c_str()));
    LOG_INFO("host:%s,port:%s,pwd:%s", host.c_str(), port.c_str(), pwd.c_str());
}

RedisMgr::~RedisMgr() {
    Close();
}
//在构造时就连接了，不需要了
// bool RedisMgr::Connect(const std::string &host, int port) {
//     this->_connect = redisConnect(host.c_str(), port);
//     if (this->_connect != NULL && this->_connect->err) {
//         LOG_INFO("connect error,%s", connect->errstr);
//         return false;
//         }
//     }
//     return true;
// }

bool RedisMgr::Get(const std::string &key, std::string &value) {
    auto connect = _con_pool->getConnections();
    if (connect == nullptr) {
        return false;
    }
    auto reply = (redisReply *)redisCommand(connect, "GET %s", key.c_str());
    if (reply == NULL) {
        LOG_INFO("[ GET  , %s, ] failed", key.c_str());
        freeReplyObject(reply);
        return false;
    }
    if (reply->type != REDIS_REPLY_STRING) {
        LOG_INFO("[ GET  , %s, ] failed", key.c_str());
        freeReplyObject(reply);
        return false;
    }
    value = reply->str;
    freeReplyObject(reply);
    LOG_INFO("Succeed to execute command [ GET %s]", key.c_str());
    _con_pool->returnConnection(connect);
    return true;
}

bool RedisMgr::Set(const std::string &key, const std::string &value) {
    auto connect = _con_pool->getConnections();
    if (connect == nullptr) {
        return false;
    }
    auto reply = (redisReply *)redisCommand(connect, "SET %s %s", key.c_str(), value.c_str());
    //返回NULL则说明执行失败
    if (reply == NULL) {
        LOG_INFO("Execut command [ SET %s,%sfailure ! ", key.c_str(), value.c_str());
        freeReplyObject(reply);
        return false;
    }
    //如果执行失败则释放连接
    if (!(reply->type == REDIS_REPLY_STATUS
          && (strcmp(reply->str, "OK") == 0 || strcmp(reply->str, "ok") == 0))) {
        freeReplyObject(reply);
        return false;
    }
    //执行成功释放redisCommand执行后返回的redisReply所占用的内存
    freeReplyObject(reply);
    LOG_INFO("Execut command [ SET %s,%s success ! ", key.c_str(), value.c_str());
    _con_pool->returnConnection(connect);
    return true;
}
// bool RedisMgr::Auth(const std::string &password) {
//     reply = (redisReply *)redisCommand(this->_connect, "AUTH %s", password.c_str());
//     if (reply->type == REDIS_REPLY_ERROR) {
//         LOG_INFO("Auth failed");
//         //执行成功 释放redisCommand执行后返回的redisReply所占用的内存
//         freeReplyObject(reply);
//         return false;
//     } else {
//         //执行成功 释放redisCommand执行后返回的redisReply所占用的内存
//         freeReplyObject(reply);
//         LOG_INFO("Auth success");
//         return true;
//     }
// }

// bool RedisMgr::Auth(const std::string &password) {
//     auto connect = _con_pool->getConnections();
//     if (connect == nullptr) {
//         return false;
//     }
//     // 如果密码为空，直接返回 true（假设 Redis 未设置密码）
//     if (password.empty()) {
//         LOG_INFO("No password required, Auth skipped");
//         return true;
//     }

//     // 执行 AUTH 命令
//     auto reply = (redisReply *)redisCommand(connect, "AUTH %s", password.c_str());
//     if (reply == nullptr || reply->type == REDIS_REPLY_ERROR) {
//         LOG_INFO("Auth failed");
//         if (reply) {
//             freeReplyObject(reply);
//         }
//         return false;
//     } else {
//         LOG_INFO("Auth success");
//         freeReplyObject(reply);
//         return true;
//     }
// }

bool RedisMgr::LPush(const std::string &key, const std::string &value) {
    auto connect = _con_pool->getConnections();
    if (connect == nullptr) {
        return false;
    }
    auto reply = (redisReply *)redisCommand(connect, "LPUSH %s %s", key.c_str(), value.c_str());
    if (NULL == reply) {
        LOG_INFO("Execut command [ LPUSH %s,%s ] failure ! ", key.c_str(), value.c_str());
        freeReplyObject(reply);
    _con_pool->returnConnection(connect);

        return false;
    }
    if (reply->type != REDIS_REPLY_INTEGER || reply->integer <= 0) {
        LOG_INFO("Execut command [ LPUSH %s,%s ] failure ! ", key.c_str(), value.c_str());
        freeReplyObject(reply);
    _con_pool->returnConnection(connect);

        return false;
    }
    LOG_INFO("Execut command [ LPUSH %s,%s ] success ! ", key.c_str(), value.c_str());
    freeReplyObject(reply);
    _con_pool->returnConnection(connect);
    return true;
}

bool RedisMgr::LPop(const std::string &key, std::string &value) {
    auto connect = _con_pool->getConnections();
    if (connect == nullptr) {
        return false;
    }
    auto reply = (redisReply *)redisCommand(connect, "LPOP %s ", key.c_str());
    if (reply == nullptr || reply->type == REDIS_REPLY_NIL) {
        LOG_INFO("Execut command [ LPOP %s ] failure ! ", key.c_str());
        freeReplyObject(reply);
    _con_pool->returnConnection(connect);
        return false;
    }
    	if (reply->type == REDIS_REPLY_NIL) {
        LOG_INFO("Execut command [ LPOP %s ] failure ! ", key.c_str());
		freeReplyObject(reply);
		_con_pool->returnConnection(connect);
		return false;
	}
    value = reply->str;
    LOG_INFO("Execut command [ LPOP %s ] success ! ", key.c_str());
    freeReplyObject(reply);
    		_con_pool->returnConnection(connect);
    return true;
}

bool RedisMgr::RPush(const std::string &key, const std::string &value) {
    auto connect = _con_pool->getConnections();
    if (connect == nullptr) {
        return false;
    }
    auto reply = (redisReply *)redisCommand(connect, "RPUSH %s %s", key.c_str(), value.c_str());
    if (NULL == reply) {
        LOG_INFO("Execut command [ RPUSH %s,%s ] failure ! ", key.c_str(), value.c_str());
        freeReplyObject(reply);
        _con_pool->returnConnection(connect);
        return false;
    }
    if (reply->type != REDIS_REPLY_INTEGER || reply->integer <= 0) {
        LOG_INFO("Execut command [ RPUSH %s,%s ] failure ! ", key.c_str(), value.c_str());
        freeReplyObject(reply);
        _con_pool->returnConnection(connect);
        return false;
    }
    LOG_INFO("Execut command [ RPUSH %s,%s ] success ! ", key.c_str(), value.c_str());
    freeReplyObject(reply);
    _con_pool->returnConnection(connect);
    return true;
}

bool RedisMgr::RPop(const std::string &key, std::string &value) {
    auto connect = _con_pool->getConnections();
    if (connect == nullptr) {
        return false;
    }
    auto reply = (redisReply *)redisCommand(connect, "RPOP %s ", key.c_str());
    if (reply == nullptr || reply->type == REDIS_REPLY_NIL) {
        LOG_INFO("Execut command [ RPOP %s ] failure ! ", key.c_str());
        freeReplyObject(reply);
        _con_pool->returnConnection(connect);
        return false;
    }
    value = reply->str;
    LOG_INFO("Execut command [ RPOP %s ] success ! ", key.c_str());
    freeReplyObject(reply);
    _con_pool->returnConnection(connect);
    return true;
}

bool RedisMgr::HSet(const std::string &key, const std::string &hkey, const std::string &value) {
    auto connect = _con_pool->getConnections();
    if (connect == nullptr) {
        return false;
    }
    auto reply = (redisReply *)redisCommand(connect, "HSET %s %s %s", key.c_str(), hkey.c_str(),
                                            value.c_str());
    if (reply == nullptr || reply->type != REDIS_REPLY_INTEGER) {
        LOG_INFO("Execut command [ HSet %s,%s,%s ] failure ! ", key.c_str(), hkey.c_str(),
                 value.c_str());
        freeReplyObject(reply);
        _con_pool->returnConnection(connect);
        return false;
    }
    LOG_INFO("Execut command [ HSet %s,%s,%s ] failure ! ", key.c_str(), hkey.c_str(),
             value.c_str());
    freeReplyObject(reply);
    _con_pool->returnConnection(connect);
    return true;
}
bool RedisMgr::HSet(const char *key, const char *hkey, const char *hvalue, size_t hvaluelen) {
    const char *argv[4];
    size_t argvlen[4];
    argv[0] = "HSET";
    argvlen[0] = 4;
    argv[1] = key;
    argvlen[1] = strlen(key);
    argv[2] = hkey;
    argvlen[2] = strlen(hkey);
    argv[3] = hvalue;
    argvlen[3] = hvaluelen;
    auto connect = _con_pool->getConnections();
    if (connect == nullptr) {
        return "";
    }
    auto reply = (redisReply *)redisCommandArgv(connect, 4, argv, argvlen);
    if (reply == nullptr || reply->type != REDIS_REPLY_INTEGER) {
        LOG_INFO("Execut command [ HSet %s,%s,%s ] failure ! ", key, hkey, hvalue);
        freeReplyObject(reply);
        _con_pool->returnConnection(connect);
        return false;
    }
    LOG_INFO("Execut command [ HSet %s,%s,%s ] failure ! ", key, hkey, hvalue);
    freeReplyObject(reply);
    _con_pool->returnConnection(connect);
    return true;
}

std::string RedisMgr::HGet(const std::string &key, const std::string &hkey) {
    const char *argv[3];
    size_t argvlen[3];
    argv[0] = "HGET";
    argvlen[0] = 4;
    argv[1] = key.c_str();
    argvlen[1] = key.length();
    argv[2] = hkey.c_str();
    argvlen[2] = hkey.length();
    auto connect = _con_pool->getConnections();
    if (connect == nullptr) {
        return "";
    }
    auto reply = (redisReply *)redisCommandArgv(connect, 3, argv, argvlen);
    if (reply == nullptr || reply->type == REDIS_REPLY_NIL) {
        freeReplyObject(reply);
        LOG_INFO("Execut command [ HGet %s,%s ] failure !", key.c_str(), hkey.c_str());
        _con_pool->returnConnection(connect);
        return "";
    }
    std::string value = reply->str;
    freeReplyObject(reply);
    LOG_INFO("Execut command [ HGet %s,%s ] success !", key.c_str(), hkey.c_str());
    _con_pool->returnConnection(connect);
    return value;
}

bool RedisMgr::Del(const std::string &key) {
    auto connect = _con_pool->getConnections();
    if (connect == nullptr) {
        return false;
    }
    auto reply = (redisReply *)redisCommand(connect, "DEL %s", key.c_str());
    if (reply == nullptr || reply->type != REDIS_REPLY_INTEGER) {
        LOG_INFO("Execut command [ Del %s ] failure !", key.c_str());
        freeReplyObject(reply);
        _con_pool->returnConnection(connect);
        return false;
    }
    LOG_INFO("Execut command [ Del %s ] success !", key.c_str());
    freeReplyObject(reply);
    _con_pool->returnConnection(connect);
    return true;
}

bool RedisMgr::ExistsKey(const std::string &key) {
    auto connect = _con_pool->getConnections();
    if (connect == nullptr) {
        return false;
    }
    auto reply = (redisReply *)redisCommand(connect, "exists %s", key.c_str());
    if (reply == nullptr || reply->type != REDIS_REPLY_INTEGER || reply->integer == 0) {
        LOG_INFO("Not Found [ Key %s]  ! ", key.c_str());
        freeReplyObject(reply);
        _con_pool->returnConnection(connect);
        return false;
    }
    LOG_INFO("Found [ Key %s]  exists! ", key.c_str());
    freeReplyObject(reply);
    _con_pool->returnConnection(connect);
    return true;
}

void RedisMgr::Close() {
    _con_pool->Close();
}
