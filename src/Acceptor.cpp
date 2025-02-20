#include"Acceptor.h"

Acceptor::Acceptor() {
    serv_sock_ip4 = new Socket(CreateNonBlocingSock());
    serv_sock_ip4->SetReuseAddr(true);
    serv_sock_ip4->SetReusePort(true);
    serv_sock_ip4->SetReuseDelay(true);
    serv_sock_ip4->SetKeepAlive(true);

    InetAddress servaddr("192.168.1.60",8086);
    serv_sock_ip4->Bind(servaddr);
    serv_sock_ip4->Listen();

    loop = new EventLoop();
    
    acceptor_channel = new Channel(loop,serv_sock_ip4->GetFd(),true);
    acceptor_channel->SetReadCallback(std::bind(&Acceptor::NewConnection,this));
    acceptor_channel->EnableReading();
}
Acceptor::Acceptor(EventLoop* loop,const std::string& ip, uint16_t port):loop(loop) {
    serv_sock_ip4 = new Socket(CreateNonBlocingSock());
    serv_sock_ip4->SetReuseAddr(true);
    serv_sock_ip4->SetReusePort(true);
    serv_sock_ip4->SetReuseDelay(true);
    serv_sock_ip4->SetKeepAlive(true);
    InetAddress servaddr(ip,port);
    serv_sock_ip4->Bind(servaddr);
    serv_sock_ip4->Listen();
    acceptor_channel = new Channel(loop,serv_sock_ip4->GetFd(),true);
    acceptor_channel->SetReadCallback(std::bind(&Acceptor::NewConnection,this));
    acceptor_channel->EnableReading();
}
void Acceptor::Start(){
    loop->Run();
}
void Acceptor::NewConnection(){
    while(true){
        // 边缘触发
        InetAddress client_addr;
        Socket *client =new Socket(serv_sock_ip4->Accept(client_addr));
        client->SetIp4AndPort(client_addr.GetIp(),client_addr.GetPort());
        if(client->GetFd()<0&&errno==EAGAIN)
            break;
        cout << "accept client socket==" << client->GetFd() << " ok" << endl;
        new_connection_callback(client);
    }
}
void Acceptor::SetNewConnectionCallback(std::function<void(Socket*)> cb){
    new_connection_callback = cb;
}
Acceptor::~Acceptor() {
    delete serv_sock_ip4;
    delete acceptor_channel;
}
