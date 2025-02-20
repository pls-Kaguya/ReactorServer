#pragma once
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string>
#include<cstring>
using namespace std;

class InetAddress{
private:
    sockaddr_in sock_addr_ip4;
    sockaddr_in6 sock_addr_ip6;
public:
    InetAddress();
    //如果是监听的fd，使用此构造函数
    InetAddress(const string &ip,uint16_t port);
    //客户端连接fd使用此构造函数
    InetAddress(const sockaddr_in addr);
    const char* GetIp() const;
    uint16_t GetPort() const;
    const sockaddr* GetAddr() const;
    void SetAddr(sockaddr_in clientaddr);
    ~InetAddress();
};