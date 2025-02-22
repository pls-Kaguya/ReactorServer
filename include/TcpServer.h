#pragma once
#include "Acceptor.h"
#include "Channel.h"
#include "Connection.h"
#include <map>
#include "ThreadPool.h"

// 前向声明
class Acceptor;
class Channel;

// TcpServer 类用于管理 TCP 服务器
class TcpServer {
    private:
        EventLoop* mainloop; // 主事件循环
        std::vector<EventLoop*> sub_loop; // 子事件循环列表
        Acceptor *acceptor; // Acceptor 实例，用于接受新连接
        std::map<int, Connection*> conn_map; // 连接映射表，存储所有连接
        ThreadPool *thread_pool; // 线程池，用于处理任务
        int thread_num; // 线程数量
        
        // 回调函数
        std::function<void(spConnection)> new_connection_callback; // 新连接回调函数
        std::function<void(spConnection)> close_connection_callback; // 关闭连接回调函数
        std::function<void(spConnection)> error_connection_callback; // 错误回调函数
        std::function<void(spConnection, std::string&)> message_callback; // 消息回调函数
        std::function<void(spConnection)> send_complete_callback; // 发送完成回调函数
        std::function<void(spConnection)> timeout_callback; // 超时回调函数

    public:
        // 默认构造函数
        TcpServer();
        
        // 带参数的构造函数，初始化服务器 IP、端口和线程数
        TcpServer(const std::string& ip, uint16_t port, int thread_num = 5);
        
        // 启动服务器
        void Start();
        
        // 处理新连接
        void NewConnection(upSocket serv_sock_ip4);
        
        // 关闭连接
        void CloseConnect(spConnection conn);
        
        // 处理连接错误
        void ErrorConnect(spConnection conn);
        
        // 处理消息
        void MessageHandle(spConnection conn, std::string &message);
        
        // 处理发送完成
        void SendComplete(spConnection conn);
        
        // 处理 epoll 超时
        void EpollTimeout(EventLoop *loop);

        // 设置新连接回调函数
        void SetNewConnectionCallback(std::function<void(spConnection)> cb);
        
        // 设置关闭连接回调函数
        void SetCloseConnectionCallback(std::function<void(spConnection)> cb);
        
        // 设置错误回调函数
        void SetErrorConnectionCallback(std::function<void(spConnection)> cb);
        
        // 设置消息回调函数
        void SetMessageCallback(std::function<void(spConnection, std::string&)> cb);
        
        // 设置发送完成回调函数
        void SetSendCompleteCallback(std::function<void(spConnection)> cb);
        
        // 设置超时回调函数
        void SetTimeoutCallback(std::function<void(EventLoop*)> cb);
        
        // 析构函数
        ~TcpServer();
};

