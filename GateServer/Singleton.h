#pragma once
#include "memory"
#include <iostream>
#include <mutex>

template <typename T>
class Singleton {
protected:
    Singleton() = default;
    //删除拷贝构造
    Singleton(const Singleton<T> &) = delete;
    //删除拷贝赋值
    Singleton &operator=(const Singleton<T> &st) = delete;

    //静态成员变量，用于存储单例实例的智能指针
    //由于是静态的，在整个程序生命周期只有一个实例
    static std::shared_ptr<T> _instance;

public:
    //静态成员函数，用于获取单例实例。
    //它使用std::call_once确保实例只被创建一次，并且是线程安全的。
    static std::shared_ptr<T> GetInstance() {
        static std::once_flag s_flag;
        std::call_once(s_flag, [&]() { _instance = std::shared_ptr<T>(new T); });
        return _instance;
    }

    void PrintAddress() { std::cout << _instance.get() << std::endl; }
    ~Singleton() { std::cout << "this is Singleton destruct" << std::endl; }
};

template <typename T>
std::shared_ptr<T> Singleton<T>::_instance = nullptr;