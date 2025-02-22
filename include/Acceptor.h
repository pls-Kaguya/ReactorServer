#pragma once
#include "Channel.h"
#include "Connection.h"

// 前向声明 Channel 类
class Channel;

// Acceptor 类用于接受新的连接
class Acceptor {
    private:
        // 服务器套接字，使用 unique_ptr 管理
        upSocket serv_sock_ip4;
        
        // 事件循环
        EventLoop* loop;
        
        // 接受连接的通道，使用 unique_ptr 管理
        upChannel acceptor_channel;
        
        // 新连接回调函数
        std::function<void(upSocket)> new_connection_callback;
    public:
        // 默认构造函数
        Acceptor();
        
        // 带参数的构造函数，初始化事件循环、IP 和端口
        Acceptor(EventLoop* loop, const std::string& ip, uint16_t port);
        
        // 启动 Acceptor
        void Start();
        
        // 处理新连接
        void NewConnection();
        
        // 设置新连接回调函数
        void SetNewConnectionCallback(std::function<void(upSocket)> cb);
        
        // 析构函数
        ~Acceptor();
};