#include "EchoServer.h"

// 默认构造函数
EchoServer::EchoServer() {

}

// 带参数的构造函数，初始化服务器 IP、端口、线程数和工作线程数
EchoServer::EchoServer(const std::string& ip, uint16_t port, int thread_num, int work_thread_num)
        : server(ip, port, thread_num), work_thread_pool(work_thread_num, ThreadType::WORK) {
    // 设置新连接回调函数
    server.SetNewConnectionCallback(std::bind(&EchoServer::HandleNewConnection, this, std::placeholders::_1));
    // 设置消息回调函数
    server.SetMessageCallback(std::bind(&EchoServer::HandleMessage, this, std::placeholders::_1, std::placeholders::_2));
    // 设置发送完成回调函数
    server.SetSendCompleteCallback(std::bind(&EchoServer::HandleSendComplete, this, std::placeholders::_1));
    // 设置关闭回调函数
    server.SetCloseCallback(std::bind(&EchoServer::HandleClose, this, std::placeholders::_1));
    // 设置错误回调函数
    server.SetErrorCallback(std::bind(&EchoServer::HandleError, this, std::placeholders::_1));
    // 设置超时回调函数
    server.SetTimeOutCallback(std::bind(&EchoServer::HandleTimeOut, this, std::placeholders::_1));
}

// 启动服务器
void EchoServer::Start() {
    server.Start();
}

// 停止服务器
void EchoServer::Stop() {
    server.Stop();
}

// 处理新连接
void EchoServer::HandleNewConnection(spConnection conn) {
    std::cout << "EchoServer::HandleNewConnection" << std::endl;
    // 处理新连接的逻辑
}

// 处理消息
void EchoServer::HandleMessage(spConnection conn, const std::string& message) {
    // 将业务逻辑添加到线程池中处理
    work_thread_pool->AddTask(std::bind(&EchoServer::HandleTask, this, conn, message));
}

// 处理任务
void EchoServer::HandleTask(spConnection conn, std::string& message) {
    message = "recv ok, server ok";
    conn->Send(message.c_str(), message.size(), 0);
}

// 处理发送完成
void EchoServer::HandleSendComplete(spConnection conn) {
    std::cout << "EchoServer::HandleSendComplete" << std::endl;
    // 处理发送完成的逻辑
    conn->Close();
}

// 处理关闭连接
void EchoServer::HandleClose(spConnection conn) {
    std::cout << "EchoServer::HandleClose" << std::endl;
    // 处理关闭连接的逻辑
    conn->Close();
}

// 处理错误
void EchoServer::HandleError(spConnection conn) {
    std::cout << "EchoServer::HandleError" << std::endl;
    // 处理错误的逻辑
    conn->Close();
}

// 处理超时
void EchoServer::HandleTimeOut(EventLoop* loop) {
    std::cout << "EchoServer::HandleTimeOut" << std::endl;
    // 处理超时的逻辑
    loop->Stop();
}



