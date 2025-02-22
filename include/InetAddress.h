#pragma once
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string>
#include <cstring>
using namespace std;

// InetAddress 类用于管理 IP 地址和端口
class InetAddress {
private:
    sockaddr_in sock_addr_ip4; // IPv4 地址结构
    sockaddr_in6 sock_addr_ip6; // IPv6 地址结构
public:
    // 默认构造函数
    InetAddress();
    
    // 带参数的构造函数，用于初始化监听的文件描述符
    InetAddress(const string &ip, uint16_t port);
    
    // 带参数的构造函数，用于初始化客户端连接的文件描述符
    InetAddress(const sockaddr_in addr);
    
    // 获取 IP 地址
    const char* GetIp() const;
    
    // 获取端口号
    uint16_t GetPort() const;
    
    // 获取 sockaddr 结构体
    const sockaddr* GetAddr() const;
    
    // 设置 sockaddr_in 结构体
    void SetAddr(sockaddr_in clientaddr);
    
    // 析构函数
    ~InetAddress();
};