#pragma once
#include"InetAddress.h"
#include"Socket.h"
#include"Epoll.h"
#include"EventLoop.h"
#include"functional"
class EventLoop;
class Socket;
class Epoll;

class Channel{
    private:
        int m_fd; // 文件描述符
        Epoll *ep = nullptr; // Epoll 实例指针
        EventLoop *loop = nullptr; // EventLoop 实例指针
        bool in_epoll = false; // 是否在 epoll 实例中
        uint32_t events = 0; // 关注的事件
        uint32_t revents = 0; // 实际发生的事件
        bool is_listen=false; 
        std::function<void()> read_callback;
        std::function<void()> write_callback;
        std::function<void()> error_callback;
        std::function<void()> close_callback;
    public:
        Channel(); // 默认构造函数
        Channel(EventLoop* loop, int fd,bool isliten); // 带参数的构造函数
        int GetFd(); // 获取文件描述符
        void SetEt(); // 设置边缘触发
        void EnableReading(); // 启用读事件
        void DisableReading(); // 禁用读事件
        void EnableWriting(); // 启用写事件
        void DisableWriting(); // 禁用写事件
        void SetInEpoll(); // 设置在 epoll 实例中
        void SetRevent(uint32_t ev); // 设置实际发生的事件
        bool GetInEpoll(); // 获取是否在 epoll 实例中
        uint32_t GetEvents(); // 获取关注的事件
        uint32_t GetRevent(); // 获取实际发生的事件
        void EventHandle(); // 处理事件i
        void MessageHandle(); // 处理消息
        void SetReadCallback(std::function<void()> cb);
        void SetWriteCallback(std::function<void()> cb);
        void SetErrorCallback(std::function<void()> cb);
        void SetCloseCallback(std::function<void()> cb);
        ~Channel(); // 析构函数
};