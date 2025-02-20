#pragma once
#include<functional>
#include"Epoll.h"

class Epoll;
class Channel;
class EventLoop{
    private:
        Epoll *ep;
        std::function<void(EventLoop*)> timeout_callback;
    public:
        EventLoop();
        void Run();
        Epoll* GetEpoll();
        void UpdateChannel(Channel *ch);
        void SetTimeoutCallback(std::function<void(EventLoop*)> cb);
        ~EventLoop();
};