#include "Acceptor.h"

// 默认构造函数，初始化服务器套接字和事件循环
Acceptor::Acceptor() {
    // 创建非阻塞套接字并设置套接字选项
    serv_sock_ip4 = std::make_unique<Socket>(CreateNonBlockingSock());
    serv_sock_ip4->SetReuseAddr(true);
    serv_sock_ip4->SetReusePort(true);
    serv_sock_ip4->SetReuseDelay(true);
    serv_sock_ip4->SetKeepAlive(true);

    // 绑定地址并监听端口
    InetAddress servaddr("192.168.1.60", 8086);
    serv_sock_ip4->Bind(servaddr);
    serv_sock_ip4->Listen();

    // 创建事件循环
    loop = new EventLoop();
    
    // 创建通道并设置读回调函数
    acceptor_channel = std::make_unique<Channel>(loop, serv_sock_ip4->GetFd(), true);
    acceptor_channel->SetReadCallback(std::bind(&Acceptor::NewConnection, this));
    acceptor_channel->EnableReading();
}

// 带参数的构造函数，初始化事件循环、IP 和端口
Acceptor::Acceptor(EventLoop* loop, const std::string& ip, uint16_t port) : loop(loop) {
    // 创建非阻塞套接字并设置套接字选项
    serv_sock_ip4 = std::make_unique<Socket>(CreateNonBlockingSock());
    serv_sock_ip4->SetReuseAddr(true);
    serv_sock_ip4->SetReusePort(true);
    serv_sock_ip4->SetReuseDelay(true);
    serv_sock_ip4->SetKeepAlive(true);

    // 绑定地址并监听端口
    InetAddress servaddr(ip, port);
    serv_sock_ip4->Bind(servaddr);
    serv_sock_ip4->Listen();

    // 创建通道并设置读回调函数
    acceptor_channel = std::make_unique<Channel>(loop, serv_sock_ip4->GetFd(), true);
    acceptor_channel->SetReadCallback(std::bind(&Acceptor::NewConnection, this));
    acceptor_channel->EnableReading();
}

// 启动 Acceptor，开始事件循环
void Acceptor::Start() {
    loop->Run();
}

// 处理新连接
void Acceptor::NewConnection() {
    while (true) {
        // 边缘触发模式下处理新连接
        InetAddress client_addr;
        auto client = std::make_unique<Socket>(serv_sock_ip4->Accept(client_addr));
        client->SetIp4AndPort(client_addr.GetIp(), client_addr.GetPort());
        if (client->GetFd() < 0 && errno == EAGAIN)
            break;
        std::cout << "accept client socket==" << client->GetFd() << " ok" << std::endl;
        // 调用新连接回调函数
        new_connection_callback(std::move(client));
    }
}

// 设置新连接回调函数
void Acceptor::SetNewConnectionCallback(std::function<void(upSocket)> cb) {
    new_connection_callback = cb;
}

// 析构函数，unique_ptr 会自动释放资源
Acceptor::~Acceptor() {
    // unique_ptr 会自动释放资源
}
