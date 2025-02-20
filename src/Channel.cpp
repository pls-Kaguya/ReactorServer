#include "Channel.h"
/*class Channel{
    private:
        int m_fd; // 文件描述符
        Epoll *ep = nullptr; // Epoll 实例指针
        bool in_epoll = false; // 是否在 epoll 实例中
        uint32_t events = 0; // 关注的事件
        uint32_t revents = 0; // 实际发生的事件
        boll is_listen=false; 
    public:
        Channel(); // 默认构造函数
        Channel(Epoll* ep, int fd,bool isliten); // 带参数的构造函数
        int GetFd(); // 获取文件描述符
        void SetEt(); // 设置边缘触发
        void EnableReading(); // 启用读事件
        void SetInEpoll(); // 设置在 epoll 实例中
        void SetRevent(uint32_t ev); // 设置实际发生的事件
        bool GetInEpoll(); // 获取是否在 epoll 实例中
        uint32_t GetEvents(); // 获取关注的事件
        uint32_t GetRevent(); // 获取实际发生的事件
        void EventHandle(Socket *serv_sock_ip4); // 处理事件
        void AcceptConnection(Socket *serv_sock_ip4); // 接受连接
        void MessageHandle(); // 处理消息
        ~Channel(); // 析构函数
};*/
// 默认构造函数
Channel::Channel() {

}

// 带参数的构造函数
Channel::Channel(EventLoop* loop, int fd,bool islisten) : loop(loop), m_fd(fd) , is_listen(islisten){
   
}

// 获取文件描述符
int Channel::GetFd() {
    return m_fd;
}

// 设置边缘触发
void Channel::SetEt() {
    events = events | EPOLLET;
}

// 启用读事件
void Channel::EnableReading() {
    events |= EPOLLIN;
    loop->UpdateChannel(this);
}
//禁用读事件
void Channel::DisableReading(){
    events &= ~EPOLLIN;
    loop->UpdateChannel(this);
}
//启用写事件
void Channel::EnableWriting(){
    events |= EPOLLOUT;
    loop->UpdateChannel(this);
}
//禁用写事件
void Channel::DisableWriting(){
    events &= ~EPOLLOUT;
    loop->UpdateChannel(this);
}
// 设置在 epoll 实例中
void Channel::SetInEpoll() {
    in_epoll = true;
}

// 设置实际发生的事件
void Channel::SetRevent(uint32_t ev) {
    revents = ev;
}

// 获取是否在 epoll 实例中
bool Channel::GetInEpoll() {
    return in_epoll;
}

// 获取关注的事件
uint32_t Channel::GetEvents() {
    return events;
}

// 获取实际发生的事件
uint32_t Channel::GetRevent() {
    return revents;
}

// 处理事件
void Channel::EventHandle() {
     // 如果就绪的文件描述符是监听套接字，表示有新的客户端连接
    if(revents & EPOLLRDHUP){//如果对方关闭连接
        close_callback();
    }else if(revents & (EPOLLIN|EPOLLPRI)){ // 处理读事件
        if(read_callback){
            read_callback();
        }
    }else if(revents&EPOLLOUT){ // 处理写事件
        write_callback();
    }else{
        error_callback();
    }
}

void Channel::MessageHandle() {// 处理消息
        // 处理现有客户端的消息
        char buffer[2048];
        memset(buffer, 0, sizeof(buffer));
        ssize_t readn;
        // 接收客户端消息
        while(1){
            readn=recv(m_fd, buffer, sizeof(buffer),0);
            if(readn>0){
                // 数据读取完成
                // 打印接收到的消息
                cout << "recv(client==" << m_fd << ") message ==" << buffer << endl;
                // 清空缓冲区并发送响应消息
                memset(buffer, 0, sizeof(buffer));
                strcpy(buffer, "recv ok, server ok");
                send(m_fd, buffer, strlen(buffer), 0);
            }else if(readn==0){
                // 如果接收失败或客户端断开连接，关闭套接字
                cout << "client socket==" <<m_fd << " disconnected" << endl;
                close(m_fd);
            }else if(readn==-1&&errno == EINTR){
                continue;
            }else if((readn==-1)&&(errno==EAGAIN)||(errno==EWOULDBLOCK)){
                break;
            } 
            break;
        }
}

void Channel::SetReadCallback(std::function<void()> cb){
    read_callback=cb;
}
void Channel::SetWriteCallback(std::function<void()> cb){
    write_callback=cb;
}
void Channel::SetErrorCallback(std::function<void()> cb){
    error_callback=cb;
}
void Channel::SetCloseCallback(std::function<void()> cb){
    close_callback=cb;
}
// 析构函数
Channel::~Channel() {

}