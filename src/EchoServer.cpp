#include"EchoServer.h"

EchoServer::EchoServer(){

}

EchoServer::EchoServer(const std::string& ip,uint_16 port):server(ip,port){
    server.SetNewConnectionCallback(std::bind(&EchoServer::HandleNewConnection,this,std::placeholders::_1));
    server.SetMessageCallback(std::bind(&EchoServer::HandleMessage,this,std::placeholders::_1,std::placeholders::_2));
    server.SetSendCompleteCallback(std::bind(&EchoServer::HandleSendComplete,this,std::placeholders::_1));
    server.SetCloseCallback(std::bind(&EchoServer::HandleClose,this,std::placeholders::_1));
    server.SetErrorCallback(std::bind(&EchoServer::HandleError,this,std::placeholders::_1));
    server.SetTimeOutCallback(std::bind(&EchoServer::HandleTimeOut,this,std::placeholders::_1));
}

void EchoServer::Start(){
    server.Start();
}

void EchoServer::Stop(){
    server.Stop();
}
void EchoServer::HandleNewConnection(Connection* conn){
    std::cout<<"EchoServer::HandleNewConnection"<<std::endl;
    //to do
}
void EchoServer::HandleMessage(Connection* conn,const std::string& message){
    message = "recv ok, server ok";
 
    conn->Send(message.c_str(),message.size(),0);
}
void EchoServer::HandleSendComplete(Connection* conn){
    std::cout<<"EchoServer::HandleSendComplete"<<std::endl;
    //to do
    conn->Close();
}
void EchoServer::HandleClose(Connection* conn){
    std::cout<<"EchoServer::HandleClose"<<std::endl;
    //to do
    conn->Close();
}
void EchoServer::HnadError(Connection* conn){
    std::cout<<"EchoServer::HnadError"<<std::endl;
    //to do
    conn->Close();
}
void EchoServer::HandleTimeOut(EventLoop* loop){
    std::cout<<"EchoServer::HandleTimeOut"<<std::endl;
    //to do
    loop->Stop();
}



