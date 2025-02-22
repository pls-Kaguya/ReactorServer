#include "InetAddress.h"


// 默认构造函数
InetAddress::InetAddress() {
    // 初始化sockaddr_in结构体
    memset(&sock_addr_ip4, 0, sizeof(sock_addr_ip4));
}

// 使用IP地址和端口号的构造函数
InetAddress::InetAddress(const string &ip, uint16_t port) {
    sock_addr_ip4.sin_family = AF_INET;
    sock_addr_ip4.sin_addr.s_addr = inet_addr(ip.c_str());
    sock_addr_ip4.sin_port = htons(port);
}

// 使用sockaddr_in结构体的构造函数
InetAddress::InetAddress(const sockaddr_in addr) : sock_addr_ip4(addr) {

}

// 获取IP地址
const char* InetAddress::GetIp() const {
    return inet_ntoa(sock_addr_ip4.sin_addr);
}

// 获取端口号
uint16_t InetAddress::GetPort() const {
    return ntohs(sock_addr_ip4.sin_port);
}

// 获取sockaddr结构体
const sockaddr* InetAddress::GetAddr() const {
    return (sockaddr*)&sock_addr_ip4;
}

// 设置sockaddr_in结构体
void InetAddress::SetAddr(sockaddr_in clientaddr) {
    sock_addr_ip4 = clientaddr;
}

// 析构函数
InetAddress::~InetAddress() {

}