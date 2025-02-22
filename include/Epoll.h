#pragma once
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <errno.h>
#include <string>
#include <strings.h>
#include <sys/epoll.h>
#include <vector>
#include <unistd.h>
#include "Channel.h"

// 前向声明 Channel 类
class Channel;

// Epoll 类用于管理 epoll 实例及其事件
class Epoll {
    private:
        int epoll_fd = -1; // epoll 文件描述符
        epoll_event evs[1024]; // 用于存储 epoll 事件的数组
        
    public:
        // 构造函数，初始化 epoll 实例
        Epoll();
        
        // 添加文件描述符到 epoll 实例
        void AddFd(int fd, uint32_t op);
        
        // 更新 Channel 对象的事件
        void UpdateChannel(Channel *ch);
        
        // 从 epoll 实例中移除 Channel 对象
        void RemoveChannel(Channel* ch);
        
        // 事件循环，等待事件发生并返回就绪的 Channel 对象
        std::vector<Channel *> EventLoop(int timeout = -1);
        
        // 析构函数，关闭 epoll 文件描述符
        ~Epoll();
};
