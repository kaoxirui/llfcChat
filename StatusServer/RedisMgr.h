#pragma once

#include "Singleton.h"
#include "const.h"

class RedisConPool {
public:
    RedisConPool(size_t poolSize, const char *host, int port, const char *pwd)
        : _poolSize(poolSize), _host(host), _port(port), _b_stop(false), _pwd(pwd), _counter(0) {
        for (size_t i = 0; i < _poolSize; i++) {
            auto *context = redisConnect(host, port);
            if (context == nullptr || context->err != 0) {
                // 连接失败且 context 不为空，则手动释放 context
                if (context != nullptr) {
                    redisFree(context);
                }
                continue;
            }

            if (pwd != nullptr && strlen(pwd) > 0) {
                LOG_DEBUG("Password is set, attempting AUTH");
                auto reply = (redisReply *)redisCommand(context, "AUTH %s", pwd);
                if (reply->type == REDIS_REPLY_ERROR) {
                    LOG_INFO("AUTH FAILED");
                    freeReplyObject(reply);
                    redisFree(context);
                    continue;
                }
                freeReplyObject(reply);
                LOG_INFO("AUTH success");
            } else {
                LOG_INFO("No password set, skip AUTH");
            }

            _connections.push(context);
        }

        _check_thread = std::thread([this]() {
            while (!_b_stop) {
                _counter++;
                if (_counter >= 60) {
                    checkThread();
                    _counter = 0;
                }
                std::this_thread::sleep_for(std::chrono::seconds(1)); // 每隔 1 秒检查一次
            }
        });
    }
    ~RedisConPool() {
        std::lock_guard<std::mutex> lock(_mutex);
        while (!_connections.empty()) {
            _connections.pop();
        }
    }
    void clearConnections() {
        std::lock_guard<std::mutex> lock(_mutex);
        while (!_connections.empty()) {
            auto *context = _connections.front();
            redisFree(context);
            _connections.pop();
        }
    }

    redisContext *getConnections() {
        std::unique_lock<std::mutex> lock(_mutex);
        _cond.wait(lock, [this] {
            //池子不能用了，return true线程就不会挂起在这了
            if (_b_stop) {
                return true;
            }
            //池子能用，但没有了，返回false，线程挂起。否则继续往下走，连接够用
            return !_connections.empty();
        });
        if (_b_stop) {
            return nullptr;
        }
        auto *context = _connections.front();
        _connections.pop();
        return context;
    }

    void returnConnection(redisContext *context) {
        std::lock_guard<std::mutex> lock(_mutex);
        if (_b_stop) {
            return;
        }
        _connections.push(context);
        _cond.notify_one();
    }

    void Close() {
        _b_stop = true;
        _cond.notify_all();
        _check_thread.join();
    }

private:
    void checkThread() {
        std::lock_guard<std::mutex> lock(_mutex);
        if (_b_stop) {
            return;
        }
        auto pool_size = _connections.size();
        for (int i = 0; i < pool_size && !_b_stop; i++) {
            auto *context = _connections.front();
            _connections.pop();
            try {
                auto reply = (redisReply *)redisCommand(context, "PING");
                if (!reply) {
                    LOG_INFO("reply is null, redis ping failed:");
                    _connections.push(context);
                    continue;
                }
                freeReplyObject(reply);
                _connections.push(context);
            } catch (std::exception &exp) {
                LOG_ERROR("Error keeping connection alive: %s", exp.what());
                redisFree(context);
                context = redisConnect(_host.c_str(), _port);
                if (context == nullptr || context->err != 0) {
                    if (context != nullptr) {
                        redisFree(context);
                    }
                    continue;
                }
                auto reply = (redisReply *)redisCommand(context, "AUTH %s", _pwd.c_str());
                if (reply->type == REDIS_REPLY_ERROR) {
                    LOG_INFO("AUTH FAILED");
                    freeReplyObject(reply);
                    continue;
                }
                // 执行成功 释放redisCommand执行后返回的redisReply所占用的内存
                freeReplyObject(reply);
                LOG_INFO("AUTH success");
                _connections.push(context);
            }
        }
    }
    std::atomic<bool> _b_stop;
    size_t _poolSize;
    std::string _host;
    int _port;
    std::string _pwd;
    //redisContext是hiredis库中表示redis连接的结构体
    //使用这只可以避免拷贝整个结构体，提高效率
    std::queue<redisContext *> _connections;
    std::mutex _mutex;
    std::condition_variable _cond;
    int _counter;
    std::thread _check_thread;
};

class RedisMgr : public Singleton<RedisMgr>, public std::enable_shared_from_this<RedisMgr> {
    friend class Singleton<RedisMgr>;

public:
    ~RedisMgr();
    // bool Connect(const std::string &host, int port);
    bool Get(const std::string &key, std::string &value);
    bool Set(const std::string &key, const std::string &value);
    // bool Auth(const std::string &password);
    bool LPush(const std::string &key, const std::string &value);
    bool LPop(const std::string &key, std::string &value);
    bool RPush(const std::string &key, const std::string &value);
    bool RPop(const std::string &key, std::string &value);
    bool HSet(const std::string &key, const std::string &hkey, const std::string &value);
    bool HSet(const char *key, const char *hkey, const char *hvalue, size_t hvaluelen);
    std::string HGet(const std::string &key, const std::string &hkey);
    bool Del(const std::string &key);
    bool ExistsKey(const std::string &key);
    void Close();

private:
    RedisMgr();
    // redisContext *_connect;
    // redisReply *_reply;
    std::unique_ptr<RedisConPool> _con_pool;
};