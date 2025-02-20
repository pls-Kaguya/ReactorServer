#include "Socket.h"

/*class Socket{
    private:
        const int fd;
    public:
        Socket(int fd);
        void SetReuseAddr(bool on);
        void SetReusePort(bool on);
        void SetReuseDelay(bool on);
        void SetKeepAlive(bool on);
        void Bind(const InetAddress& servaddr);
        void Listen(int num=128);
        void Accept(InetAddress& &clientaddr);

        int GetFd() const;
        ~Socket();
}*/

// 创建非阻塞套接字
int CreateNonBlocingSock(){
    int listen_sock_ip4 = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, IPPROTO_TCP);
    if(listen_sock_ip4 < 0){
        perror("socket() failed");
        exit(-1);
    }
    return listen_sock_ip4;
}

// 设置地址重用选项
void Socket::SetReuseAddr(bool on){
    int optval = on ? 1 : 0;
    setsockopt(fd_, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
}

// 设置端口重用选项
void Socket::SetReusePort(bool on){
    int optval = on ? 1 : 0;
    setsockopt(fd_, SOL_SOCKET, SO_REUSEPORT, &optval, sizeof(optval));
}

// 设置无延迟选项
void Socket::SetReuseDelay(bool on){
    int optval = on ? 1 : 0;
    setsockopt(fd_, IPPROTO_TCP, TCP_NODELAY, &optval, sizeof(optval));
}

// 设置保持连接选项
void Socket::SetKeepAlive(bool on){
    int optval = on ? 1 : 0;
    setsockopt(fd_, SOL_SOCKET, SO_KEEPALIVE, &optval, sizeof(optval));
}

// 绑定地址和端口
void Socket::Bind(const InetAddress& servaddr){
    if(bind(fd_, servaddr.GetAddr(), sizeof(sockaddr_in)) < 0){
        perror("bind() failed");
        close(fd_);
        exit(-1);
    }
    SetIp4AndPort(servaddr.GetIp(), servaddr.GetPort());
}

// 开始监听
void Socket::Listen(int num){
    if(listen(fd_, num) != 0){
        perror("listen() failed");
        close(fd_);
        exit(-1);
    }
}

// 接受客户端连接
int Socket::Accept(InetAddress &clientaddr){
    sockaddr_in peeraddr;
    socklen_t len = sizeof(peeraddr);
    int clientfd = accept4(fd_, (struct sockaddr*)&peeraddr, &len, SOCK_NONBLOCK);
    clientaddr.SetAddr(peeraddr); 
    return clientfd;
}
int Socket::GetFd() const{
    return fd_;
}
void Socket::SetIp4AndPort(Const std::string& ip, uint16_t port){
    this.ip = ip;
    this.port = port;
}

// 构造函数
Socket::Socket(int fd):fd_(fd) {

}

// 析构函数
Socket::~Socket(){
    close(fd_);
}