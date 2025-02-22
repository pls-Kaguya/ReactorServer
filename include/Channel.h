#pragma once

#include "InetAddress.h"
#include "Socket.h"
#include "Epoll.h"
#include "EventLoop.h"
#include <functional>

// 前向声明
class EventLoop;
class Socket;
class Epoll;

// Channel 类用于管理文件描述符及其事件
class Channel {
    private:
        int m_fd; // 文件描述符
        Epoll *ep = nullptr; // Epoll 实例指针
        EventLoop *loop = nullptr; // EventLoop 实例指针
        bool in_epoll = false; // 是否在 epoll 实例中
        uint32_t events = 0; // 关注的事件
        uint32_t revents = 0; // 实际发生的事件
        bool is_listen = false; // 是否为监听套接字
        std::function<void()> read_callback; // 读事件回调函数
        std::function<void()> write_callback; // 写事件回调函数
        std::function<void()> error_callback; // 错误事件回调函数
        std::function<void()> close_callback; // 关闭事件回调函数
    public:
        // 默认构造函数
        Channel();
        
        // 带参数的构造函数，初始化事件循环、文件描述符和是否为监听套接字
        Channel(EventLoop* loop, int fd, bool is_listen);
        
        // 获取文件描述符
        int GetFd();
        
        // 设置边缘触发
        void SetEt();
        
        // 启用读事件
        void EnableReading();
        
        // 禁用读事件
        void DisableReading();
        
        // 启用写事件
        void EnableWriting();
        
        // 禁用写事件
        void DisableWriting();
        
        // 禁用所有事件
        void DisableAll();
        
        // 从事件循环中删除 Channel
        void Remove();
        
        // 设置在 epoll 实例中
        void SetInEpoll();
        
        // 设置实际发生的事件
        void SetRevent(uint32_t ev);
        
        // 获取是否在 epoll 实例中
        bool GetInEpoll();
        
        // 获取关注的事件
        uint32_t GetEvents();
        
        // 获取实际发生的事件
        uint32_t GetRevent();
        
        // 处理事件
        void EventHandle();
        
        // 处理消息
        void MessageHandle();
        
        // 设置读事件回调函数
        void SetReadCallback(std::function<void()> cb);
        
        // 设置写事件回调函数
        void SetWriteCallback(std::function<void()> cb);
        
        // 设置错误事件回调函数
        void SetErrorCallback(std::function<void()> cb);
        
        // 设置关闭事件回调函数
        void SetCloseCallback(std::function<void()> cb);
        
        // 析构函数
        ~Channel();
};

// 使用 unique_ptr 管理 Channel 实例
using upChannel = std::unique_ptr<Channel>;