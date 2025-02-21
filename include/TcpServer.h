#pragma once
#include"Acceptor.h"
#include"Channel.h"
#include"Connection.h"
#include<map>
#include"ThreadPool.h"
class Accpetor;
class Channel;
class TcpServer{
    private:
        EventLoop* mainloop;
        std::vector<EventLoop*> sub_loop;
        Acceptor *acceptor;
        std::map<int,Connection*> conn_map;
        ThreadPool *sub_thread_pool;
        int thread_num;
        std::function<void(Connection*)> new_connection_callback;
        std::function<void(Connection*)> close_connection_callback;
        std::function<void(Connection*)> error_connection_callback;
        std::function<void(Connection*,std::string)> message_callback;
        std::function<void(Connection*)> send_complete_callback;
        std::function<void(EventLoop*)> timeout_callback;

    public:
        TcpServer();
        TcpServer(const std::string& ip, uint16_t port,int thread_num=5);
        void Start();
        void NewConnection(Socket *serv_sock_ip4);
        void CloseConnect(Connection *conn);
        void ErrorConnect(Connection *conn);
        void MessageHandle(Connection *conn,std::string &message);
        void SendComplete(Connection *conn);
        void EpollTimeout(EventLoop *loop);

        void SetNewConnectionCallback(std::function<void(Connection*) cb);
        void SetCloseConnectionCallback(std::function<void(Connection*) cb);
        void SetErrorConnectionCallback(std::function<void(Connection*) cb);
        void SetMessageCallback(std::function<void(Connection*,std::string) cb);
        void SetSendCompleteCallback(std::function<void(Connection*) cb);
        void SetTimeoutCallback(std::function<void(EventLoop*) cb);
        ~TcpServer();
};

