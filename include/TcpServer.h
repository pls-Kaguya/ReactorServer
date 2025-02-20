#pragma once
#include"Acceptor.h"
#include"Channel.h"
#include"Connection.h"
#include<map>

class Accpetor;
class Channel;
class TcpServer{
    private:
        EventLoop* loop;
        Acceptor *acceptor;
        std::map<int,Connection*> conn_map;

    public:
        TcpServer();
        TcpServer(const std::string& ip, uint16_t port);
        void Start();
        void NewConnection(Socket *serv_sock_ip4);
        void CloseConnect(Connection *conn);
        void ErrorConnect(Connection *conn);
        void MessageHandle(Connection *conn,std::string message);
        void SendComplete(Connection *conn);
        void EpollTimeout(EventLoop *loop);
        ~TcpServer();
};

