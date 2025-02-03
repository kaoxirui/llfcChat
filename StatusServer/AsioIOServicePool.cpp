#include "AsioIOServicePool.h"
#include <memory>

AsioIOServicePool::AsioIOServicePool(std::size_t size)
    : _ioServices(size), _works(size), _nextIOService(0) {
    for (std::size_t i = 0; i < size; i++) {
        _works[i] = std::unique_ptr<Work>(new Work(_ioServices[i]));
    }
    //如果没有事件，io_service执行run会直接退出，线程也就退出了
    //work和ioservice绑定则不会
    for (std::size_t i = 0; i < _ioServices.size(); i++) {
        _threads.emplace_back([this, i]() { _ioServices[i].run(); });
    }
}

//RAII
//自己创建的理应由自己停掉
AsioIOServicePool::~AsioIOServicePool() {
    Stop();
    std::cout << "---------------- AsioIOServicePool destruct ----------------" << std::endl;
}

boost::asio::io_context &AsioIOServicePool::GetIOService() {
    auto &service = _ioServices[_nextIOService++];
    if (_nextIOService >= _ioServices.size()) {
        _nextIOService = 0;
    }
    return service;
}

void AsioIOServicePool::Stop() {
    //因为仅仅执行work.reset并不能让iocontext从run的状态中退出
    //当iocontext已经绑定了读或写的监听事件后，还需要手动stop该服务。
    for (auto &work : _works) {
        work->get_io_context().stop();
        //相当于work变为空指针
        work.reset();
    }
    for (auto &t : _threads) {
        t.join();
    }
}
