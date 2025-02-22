#include "TcpServer.h"

/*class TcpServer{
    private:
        Socket serv_sock_ip4;
        Epoll ep;
        Channel *serv_ch;
    public:
        TcpServer();
        void Start();
        ~TcpServer();
};*/

// 默认构造函数
TcpServer::TcpServer() {
    mainloop = new EventLoop(); // 创建主事件循环
    mainloop->SetTimeoutCallback(std::bind(&TcpServer::EpollTimeout, this, std::placeholders::_1)); // 设置超时回调函数

    acceptor = new Acceptor(mainloop, "192.168.1.60", 8086); // 创建 Acceptor 实例并绑定 IP 和端口
    acceptor->SetNewConnectionCallback(std::bind(&TcpServer::NewConnection, this, std::placeholders::_1)); // 设置新连接回调函数
    
    thread_pool = new ThreadPool(thread_num, ThreadType::IO); // 创建线程池
    for (int i = 0; i < thread_num; i++) {
        sub_loop.push_back(new EventLoop()); // 创建子事件循环
        sub_loop[i]->SetTimeoutCallback(std::bind(&TcpServer::EpollTimeout, this, std::placeholders::_1)); // 设置超时回调函数
        thread_pool->AddTask(std::bind(&EventLoop::Run, sub_loop[i])); // 将子事件循环添加到线程池中运行
    }
}

// 带参数的构造函数，初始化服务器 IP、端口和线程数
TcpServer::TcpServer(const std::string& ip, uint16_t port, int num) : thread_num(num) {
    mainloop = new EventLoop(); // 创建主事件循环
    mainloop->SetTimeoutCallback(std::bind(&TcpServer::EpollTimeout, this, std::placeholders::_1)); // 设置超时回调函数

    acceptor = new Acceptor(mainloop, ip, port); // 创建 Acceptor 实例并绑定 IP 和端口
    acceptor->SetNewConnectionCallback(std::bind(&TcpServer::NewConnection, this, std::placeholders::_1)); // 设置新连接回调函数
    
    thread_pool = new ThreadPool(thread_num); // 创建线程池
    for (int i = 0; i < thread_num; i++) {
        sub_loop.push_back(new EventLoop()); // 创建子事件循环
        sub_loop[i]->SetTimeoutCallback(std::bind(&TcpServer::EpollTimeout, this, std::placeholders::_1)); // 设置超时回调函数
        thread_pool->AddTask(std::bind(&EventLoop::Run, sub_loop[i])); // 将子事件循环添加到线程池中运行
    }
}

// 启动服务器
void TcpServer::Start() {
    mainloop->Run(); // 运行主事件循环
}

// 处理新连接
void TcpServer::NewConnection(upSocket serv_sock_ip4) {
    spConnection conn(new Connection(sub_loop[serv_sock_ip4->GetFd() % thread_num], std::move(serv_sock_ip4))); // 创建新的连接实例
    conn->SetCloseCallback(std::bind(&TcpServer::CloseConnect, this, std::placeholders::_1)); // 设置关闭回调函数
    conn->SetErrorCallback(std::bind(&TcpServer::ErrorConnect, this, std::placeholders::_1)); // 设置错误回调函数
    conn->SetReadCallback(std::bind(&TcpServer::MessageHandle, this, std::placeholders::_1, std::placeholders::_2)); // 设置读回调函数
    conn->SetWriteCallback(std::bind(&TcpServer::SendComplete, this, std::placeholders::_1)); // 设置写回调函数
    conn_map[conn->GetFd()] = conn; // 将连接添加到连接映射表中
    new_connection_callback(conn); // 调用新连接回调函数
}

// 关闭连接
void TcpServer::CloseConnect(spConnection conn) {
    close_connection_callback(conn); // 调用关闭连接回调函数
    std::cout << "client (eventfd=" << conn->GetFd() << ") disconnected" << std::endl;
    conn_map.erase(conn->GetFd()); // 从连接映射表中删除连接
}

// 处理连接错误
void TcpServer::ErrorConnect(spConnection conn) {
    error_connection_callback(conn); // 调用错误回调函数
    std::cout << "client (eventfd=" << conn->GetFd() << ") disconnected" << std::endl;
    conn_map.erase(conn->GetFd()); // 从连接映射表中删除连接
}

// 处理消息
void TcpServer::MessageHandle(spConnection conn, std::string &message) {
    message_callback(conn, message); // 调用消息回调函数
}

// 处理发送完成
void TcpServer::SendComplete(spConnection conn) {
    send_complete_callback(conn); // 调用发送完成回调函数
}

// 处理 epoll 超时
void TcpServer::EpollTimeout(EventLoop *loop) {
    timeout_callback(loop); // 调用超时回调函数
}

// 设置新连接回调函数
void TcpServer::SetNewConnectionCallback(std::function<void(spConnection)> cb) {
    new_connection_callback = cb;
}

// 设置关闭连接回调函数
void TcpServer::SetCloseConnectionCallback(std::function<void(spConnection)> cb) {
    close_connection_callback = cb;
}

// 设置错误回调函数
void TcpServer::SetErrorConnectionCallback(std::function<void(spConnection)> cb) {
    error_connection_callback = cb;
}

// 设置消息回调函数
void TcpServer::SetMessageCallback(std::function<void(spConnection, std::string&)> cb) {
    message_callback = cb;
}

// 设置发送完成回调函数
void TcpServer::SetSendCompleteCallback(std::function<void(spConnection)> cb) {
    send_complete_callback = cb;
}

// 设置超时回调函数
void TcpServer::SetTimeoutCallback(std::function<void(EventLoop*)> cb) {
    timeout_callback = cb;
}

// 析构函数
TcpServer::~TcpServer() {
    delete acceptor;
    delete mainloop;
    for (auto& loop : sub_loop) {
        delete loop;
    }
    delete thread_pool;
}