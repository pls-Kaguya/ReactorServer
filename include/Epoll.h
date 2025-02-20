#pragma once
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<errno.h>
#include<string>
#include<strings.h>
#include<sys/epoll.h>
#include<vector>
#include<unistd.h>
#include"Channel.h"

class Channel;
class Epoll{
    private:
        int epoll_fd = -1;
        epoll_event evs[1024];
        
    public:
        Epoll();
        void AddFd(int fd,uint32_t op);
        void UpdateChannel(Channel *ch);
        std::vector<Channel *> EventLoop(int timeout=-1);
        ~Epoll();
};
