#pragma once
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/tcp.h>
#include<errno.h>
#include<unistd.h>
#include"InetAddress.h"
int CreateNonBlocingSock();

class Socket{
    private:
        const int fd_;
    public:
        Socket(int fd);
        void SetReuseAddr(bool on);
        void SetReusePort(bool on);
        void SetReuseDelay(bool on);
        void SetKeepAlive(bool on);
        void Bind(const InetAddress& servaddr);
        void Listen(int num=128);
        int Accept(InetAddress &clientaddr);
        void SetIp4AndPort(const std::string& ip, uint16_t port);

        int GetFd() const;
        ~Socket();
};