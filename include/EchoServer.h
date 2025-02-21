#pragma once
#include "TcpServer.h"

class EchoServer
{
public:
    EchoServer();
    EchoServer(const std::string& ip, uint16_t port);
    ~EchoServer();

    void Start();
    void Stop();


    void HandleNewConnection(Connection* conn);
    void HandleMessage(Connection* conn,const std::string &message);
    void HandleSendComplete(Connection* conn);
    void HandleClose(Connection* conn);
    void HnadError(Connection* conn);
    void HandleTimeOut(EventLoop* loop);

private:
    TcpServer server;   
};