#pragma once
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <errno.h>
#include <unistd.h>
#include <memory>
#include "InetAddress.h"

// 创建非阻塞套接字
int CreateNonBlockingSock();

// Socket 类用于管理套接字
class Socket {
    private:
        const int fd_; // 套接字文件描述符
    public:
        // 构造函数，初始化套接字文件描述符
        Socket(int fd);
        
        // 设置地址重用选项
        void SetReuseAddr(bool on);
        
        // 设置端口重用选项
        void SetReusePort(bool on);
        
        // 设置延迟重用选项
        void SetReuseDelay(bool on);
        
        // 设置保持连接选项
        void SetKeepAlive(bool on);
        
        // 绑定套接字到指定地址
        void Bind(const InetAddress& servaddr);
        
        // 监听套接字
        void Listen(int num = 128);
        
        // 接受连接并返回新的套接字文件描述符
        int Accept(InetAddress &clientaddr);
        
        // 设置 IP 地址和端口号
        void SetIp4AndPort(const std::string& ip, uint16_t port);
        
        // 获取套接字文件描述符
        int GetFd() const;
        
        // 析构函数，关闭套接字
        ~Socket();
};

// 使用 unique_ptr 管理 Socket 实例
using upSocket = std::unique_ptr<Socket>;