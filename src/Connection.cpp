#include"Connection.h"

Connection::Connection(EventLoop* loop,Socket *socket):loop(loop),client_socket(socket){ 
    connection_channel = new Channel(loop,socket->GetFd(),false);
    connection_channel->SetReadCallback(std::bind(&Connection::HandleRead,this));
    connection_channel->SetWriteCallback(std::bind(&Connection::HandleWrite,this));
    connection_channel->SetErrorCallback(std::bind(&Connection::HandleError,this));
    connection_channel->SetCloseCallback(std::bind(&Connection::HandleClose,this));
    connection_channel->SetEt();
    /*connection_channel->SetWriteCallback(std::bind(&Connection::HandleWrite,this));
    connection_channel->SetErrorCallback(std::bind(&Connection::HandleError,this));*/
    connection_channel->EnableReading();
}



int Connection::GetFd(){
    return connection_channel->GetFd();
}
void Connection::EnableReading(){
    connection_channel->EnableReading();
}

void Connection::EnableWriting(){
    connection_channel->EnableWriting();
}

void Connection::DisableWriting(){
    connection_channel->DisableWriting();
}

void Connection::Send(const std::string& message){
    output_buffer.Append(message);
    EnableWriting();
}

void Connection::Send(const char* message){
    output_buffer.Append(message);
    EnableWriting();
}

void Connection::Send(const void* message, size_t len){
    output_buffer.Append(message,len);
    EnableWriting();
}

void Connection::HandleRead(){
     // 处理现有客户端的消息
     char buffer[2048];
     memset(buffer, 0, sizeof(buffer));
     ssize_t readn;
     // 接收客户端消息
     while(1){
         readn=recv(GetFd(), buffer, sizeof(buffer),0);
         if(readn>0){
             input_buffer.Append(buffer,readn);
         }else if(readn==0){
             // 如果接收失败或客户端断开连接，关闭套接字
             HandleClose();
             break;
         }else if(readn==-1&&errno == EINTR){
             continue;
         }else if((readn==-1)&&(errno==EAGAIN)||(errno==EWOULDBLOCK)){
            while(true){
            int len;
            memcpy(&len,input_buffer.Data(),sizeof(int));
            if(input_buffer.Size()<len+sizeof(int)){
                //数据不完整
                break;
            }
            std::string message(input_buffer.Data()+sizeof(int),len);
            input_buffer.Erase(0,len+sizeof(int));
            std::cout<<"recv(client=="<<GetFd()<<") message=="<<message<<std::endl;
            // to do : 处理消息
            read_callback(this,message);
           
            }
            break;
         } 
         break;
     }
}
void Connection::HandleWrite(){
    int write = send(GetFd(),output_buffer.Data(),output_buffer.Size(),0);
    if(write>0){
        output_buffer.Erase(0,write);
    }
    if(output_buffer.Size()==0){
        DisableWriting();
        write_callback(this);
    }

}
void Connection::HandleError(){
    error_callback(this);
}
void Connection::HandleClose(){
    close_callback(this);
}
void Connection::SetCloseCallback(std::function<void(Connection*)> cb){
    close_callback = cb;
}
void Connection::SetErrorCallback(std::function<void(Connection*)> cb){
    error_callback = cb;
}
void Connection::SetReadCallback(std::function<void(Connection*)> cb){
    read_callback = cb;
}
void Connection::SetWriteCallback(std::function<void(Connection*)> cb){
    write_callback = cb;
}
Connection::~Connection(){
    delete connection_channel;
    delete client_socket;
}