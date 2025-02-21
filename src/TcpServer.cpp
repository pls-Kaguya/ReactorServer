#include"TcpServer.h"

/*class TcpServer{
    private:
        Socket serv_sock_ip4;
        Epoll ep;
        Channel *serv_ch;
    public:
        TcpServer();
        void Start();
        ~TcpServer();
};*/

// 默认构造函数
TcpServer::TcpServer() {
    loop = new EventLoop();
    acceptor = new Acceptor(loop,"192.168.1.60",8086);
    acceptor->SetNewConnectionCallback(std::bind(&TcpServer::NewConnection,this,std::placeholders::_1));
    loop->SetTimeoutCallback(std::bind(&TcpServer::EpollTimeout,this,std::placeholders::_1));
}
TcpServer::TcpServer(const std::string& ip, uint16_t port) {
    loop = new EventLoop();
    acceptor = new Acceptor(loop,ip,port);
    acceptor->SetNewConnectionCallback(std::bind(&TcpServer::NewConnection,this,std::placeholders::_1));
    loop->SetTimeoutCallback(std::bind(&TcpServer::EpollTimeout,this,std::placeholders::_1));
}
void TcpServer::Start(){
    loop->Run();
}

void TcpServer::NewConnection(Socket *serv_sock_ip4){
    Connection *conn = new Connection(loop,serv_sock_ip4);
    conn->SetCloseCallback(std::bind(&TcpServer::CloseConnect,this,std::placeholders::_1));
    conn->SetErrorCallback(std::bind(&TcpServer::ErrorConnect,this,std::placeholders::_1));
    conn->SetReadCallback(std::bind(&TcpServer::MessageHandle,this,std::placeholders::_1,std::placeholders::_2));
    conn->SetWriteCallback(std::bind(&TcpServer::SendComplete,this,std::placeholders::_1));
    conn_map[conn->GetFd()] = conn;
    new_connection_callback(conn);
}
void TcpServer::CloseConnect(Connection *conn){
    close_connection_callback(conn);
    std::cout<<"client (eventfd="<<conn->GetFd()<<") disconnected"<<endl;
    conn_map.erase(conn->GetFd());
    delete conn;
}
void TcpServer::ErrorConnect(Connection *conn){
    error_connection_callback(conn);
    std::cout<<"client (eventfd="<<conn->GetFd()<<") disconnected"<<endl;
    conn_map.erase(conn->GetFd());
    delete conn;
}
void TcpServer::MessageHandle(Connection *conn,std::string &message){
   message_callback(conn,message);
}
void TcpServer::SendComplete(Connection *conn){

    send_complete_callback(conn);
}
void TcpServer::EpollTimeout(EventLoop *loop){
    timeout_callback(loop);
}
void SetNewConnectionCallback(std::function<void(Connection*)> cb){
    new_connection_callback = cb;
}
void SetCloseConnectionCallback(std::function<void(Connection*)> cb){
    close_connection_callback = cb;
}
void SetErrorConnectionCallback(std::function<void(Connection*)> cb){
    error_connection_callback = cb;
}
void SetMessageCallback(std::function<void(Connection*,std::string)> cb){
    message_callback = cb;
}
void SetSendCompleteCallback(std::function<void(Connection*)> cb){
    send_complete_callback = cb;
}
void SetTimeoutCallback(std::function<void(EventLoop*)> cb){
    timeout_callback = cb;
}
TcpServer::~TcpServer() {
    delete acceptor;
    for(auto& conn:conn_map){
        delete conn.second;
    }
}