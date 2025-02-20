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
}
void TcpServer::CloseConnect(Connection *conn){
    std::cout<<"client (eventfd="<<conn->GetFd()<<") disconnected"<<endl;
    //close(conn->GetFd());
    conn_map.erase(conn->GetFd());
    delete conn;
}
void TcpServer::ErrorConnect(Connection *conn){
    std::cout<<"client (eventfd="<<conn->GetFd()<<") disconnected"<<endl;
    conn_map.erase(conn->GetFd());
    delete conn;
}
void TcpServer::MessageHandle(Connection *conn,std::string message){
    message = "recv ok, server ok";
    len = message.size();
    std::string tmpmsg((char*)&len,sizeof(int));
    tmpmsg.append(message);
    // 发送响应消息
    send(conn->GetFd(),tmpmsg.c_str(),tmpmsg.size(),0);
}
void TcpServer::SendComplete(Connection *conn){
    std::cout<<"send complete"<<endl;
}
void TcpServer::EpollTimeout(EventLoop *loop){
    std::cout<<"epoll timeout"<<endl;
}
TcpServer::~TcpServer() {
    delete acceptor;
    for(auto& conn:conn_map){
        delete conn.second;
    }
}