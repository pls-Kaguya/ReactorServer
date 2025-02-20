#include "Epoll.h"

/*class Epoll{
    private:
        int epoll_fd = -1; // epoll 文件描述符
        epoll_event evs[1024]; // epoll 事件数组
        
    public:
        Epoll(); // 构造函数
        void AddFd(int fd, uint32_t op); // 添加文件描述符到 epoll 实例
        void UpdateChannel(Channel *ch); // 更新或添加 Channel 到 epoll 实例
        std::vector<Channel *> EventLoop(int timeout = -1); // 事件循环
        ~Epoll(); // 析构函数
};*/

// 构造函数，创建 epoll 实例
Epoll::Epoll(){
    epoll_fd = epoll_create(1);
    if(epoll_fd == -1){
        std::cout << "epoll create() failed" << std::endl;
        exit(-1);
    }
}

// 添加文件描述符到 epoll 实例
void Epoll::AddFd(int fd, uint32_t op){
    epoll_event ev;
    ev.data.fd = fd;
    ev.events = op;
    if(epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd, &ev) == -1){
        std::cout << "AddFd() Failed" << std::endl;
        exit(-1);
    }
}

// 更新或添加 Channel 到 epoll 实例
void Epoll::UpdateChannel(Channel *ch){
    epoll_event ev;
    ev.data.ptr = ch;
    ev.events = ch->GetEvents();
    if(ch->GetInEpoll()){
        if(epoll_ctl(epoll_fd, EPOLL_CTL_MOD, ch->GetFd(), &ev) == -1){
            perror("epoll_ctl() failed");
            exit(-1);
        }
    } else {
        if(epoll_ctl(epoll_fd, EPOLL_CTL_ADD, ch->GetFd(), &ev) == -1){
            perror("epoll_ctl() failed");
            exit(-1);
        }
        ch->SetInEpoll();
    }
}

// 事件循环，返回就绪的 Channel 列表
std::vector<Channel *> Epoll::EventLoop(int timeout){
    std::vector<Channel *> channels;
    int infds = epoll_wait(epoll_fd, evs, 1024, timeout);
    bzero(evs, sizeof(evs));

    if(infds < 0){
        perror("epoll_wait() failed");
        // EBADF: 无效的文件描述符
        // EFAULT: evs 不是一个有效的指针
        // EINTR: 被信号中断
        // EINVAL: epoll_fd 不是一个有效的 epoll 文件描述符
        exit(-1);
    }
    if(infds == 0){
        // 事件超时

        return channels;
    }
    for(int i = 0; i < infds; i++){
        Channel *ch = (Channel *)evs[i].data.ptr;
        ch->SetRevent(evs[i].events);
        channels.push_back(ch);
    }
    return channels;
}

// 析构函数，关闭 epoll 文件描述符
Epoll::~Epoll(){
    close(epoll_fd);
}