#pragma once
#include"Channel.h"
#include"Connection.h"

class Channel;
class Acceptor{
    private:
        Socket *serv_sock_ip4;
        EventLoop* loop;
        Channel *acceptor_channel;
        std::function<void(Socket*)> new_connection_callback;
    public:
        Acceptor();
        Acceptor(EventLoop* loop,const std::string& ip, uint16_t port);
        void Start();
        void NewConnection();
        void SetNewConnectionCallback(std::function<void(Socket*)> cb);
        ~Acceptor();
};