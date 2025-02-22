#pragma once
#include <functional>
#include <sys/syscall.h>
#include <unistd.h>
#include "Epoll.h"

// 前向声明
class Epoll;
class Channel;

// EventLoop 类用于管理事件循环
class EventLoop {
    private:
        Epoll *ep; // Epoll 实例指针
        std::function<void(EventLoop*)> timeout_callback; // 超时回调函数
    public:
        // 构造函数，初始化 Epoll 实例
        EventLoop();
        
        // 运行事件循环
        void Run();
        
        // 获取 Epoll 实例
        Epoll* GetEpoll();
        
        // 更新 Channel 对象的事件
        void UpdateChannel(Channel *ch);
        
        // 从事件循环中移除 Channel 对象
        void RemoveChannel(Channel *ch);
        
        // 设置超时回调函数
        void SetTimeoutCallback(std::function<void(EventLoop*)> cb);
        
        // 析构函数，释放 Epoll 实例
        ~EventLoop();
};