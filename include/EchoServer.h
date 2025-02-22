#pragma once
#include "TcpServer.h"
#include "ThreadPool.h"

// EchoServer 类用于管理 Echo 服务器
class EchoServer {
public:
    // 默认构造函数
    EchoServer();
    
    // 带参数的构造函数，初始化服务器 IP、端口、线程数和工作线程数
    EchoServer(const std::string& ip, uint16_t port, int thread_num = 5, int work_thread_num = 5);
    
    // 析构函数
    ~EchoServer();

    // 启动服务器
    void Start();
    
    // 停止服务器
    void Stop();

    // 处理新连接
    void HandleNewConnection(spConnection conn);
    
    // 处理消息
    void HandleMessage(spConnection conn, const std::string &message);
    
    // 处理发送完成
    void HandleSendComplete(spConnection conn);
    
    // 处理关闭连接
    void HandleClose(spConnection conn);
    
    // 处理错误
    void HandleError(spConnection conn);
    
    // 处理超时
    void HandleTimeOut(EventLoop* loop);
    
    // 处理任务
    void HandleTask(spConnection conn, std::string &message);

private:
    // TcpServer 实例，用于管理 TCP 连接
    TcpServer server;
    
    // 工作线程池，用于处理任务
    ThreadPool *work_thread_pool;
};