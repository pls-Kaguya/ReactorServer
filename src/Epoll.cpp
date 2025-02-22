#include "Epoll.h"

// 构造函数，创建 epoll 实例
Epoll::Epoll() {
    epoll_fd = epoll_create(1); // 创建 epoll 实例
    if (epoll_fd == -1) {
        std::cout << "epoll create() failed" << std::endl;
        exit(-1); // 如果创建失败，退出程序
    }
}

// 添加文件描述符到 epoll 实例
void Epoll::AddFd(int fd, uint32_t op) {
    epoll_event ev;
    ev.data.fd = fd; // 设置文件描述符
    ev.events = op; // 设置事件类型
    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd, &ev) == -1) {
        std::cout << "AddFd() Failed" << std::endl;
        exit(-1); // 如果添加失败，退出程序
    }
}

// 更新或添加 Channel 到 epoll 实例
void Epoll::UpdateChannel(Channel *ch) {
    epoll_event ev;
    ev.data.ptr = ch; // 将 Channel 指针存储在事件中
    ev.events = ch->GetEvents(); // 获取 Channel 关注的事件类型
    if (ch->GetInEpoll()) {
        // 如果 Channel 已经在 epoll 实例中，修改其事件
        if (epoll_ctl(epoll_fd, EPOLL_CTL_MOD, ch->GetFd(), &ev) == -1) {
            perror("epoll_ctl() failed");
            exit(-1); // 如果修改失败，退出程序
        }
    } else {
        // 如果 Channel 不在 epoll 实例中，添加其事件
        if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, ch->GetFd(), &ev) == -1) {
            perror("epoll_ctl() failed");
            exit(-1); // 如果添加失败，退出程序
        }
        ch->SetInEpoll(); // 标记 Channel 已经在 epoll 实例中
    }
}

// 从 epoll 实例中移除 Channel 对象
void Epoll::RemoveChannel(Channel* ch) {
    if (ch->GetInEpoll()) {
        // 如果 Channel 在 epoll 实例中，删除其事件
        if (epoll_ctl(epoll_fd, EPOLL_CTL_DEL, ch->GetFd(), 0) == -1) {
            perror("epoll_ctl() failed");
            exit(-1); // 如果删除失败，退出程序
        }
    }
}

// 事件循环，返回就绪的 Channel 列表
std::vector<Channel *> Epoll::EventLoop(int timeout) {
    std::vector<Channel *> channels;
    int infds = epoll_wait(epoll_fd, evs, 1024, timeout); // 等待事件发生
    bzero(evs, sizeof(evs)); // 清空事件数组

    if (infds < 0) {
        perror("epoll_wait() failed");
        // 处理可能的错误
        // EBADF: 无效的文件描述符
        // EFAULT: evs 不是一个有效的指针
        // EINTR: 被信号中断
        // EINVAL: epoll_fd 不是一个有效的 epoll 文件描述符
        exit(-1); // 如果等待失败，退出程序
    }
    if (infds == 0) {
        // 事件超时
        return channels; // 返回空的 Channel 列表
    }
    for (int i = 0; i < infds; i++) {
        Channel *ch = (Channel *)evs[i].data.ptr; // 获取就绪的 Channel
        ch->SetRevent(evs[i].events); // 设置实际发生的事件
        channels.push_back(ch); // 将就绪的 Channel 添加到列表中
    }
    return channels; // 返回就绪的 Channel 列表
}

// 析构函数，关闭 epoll 文件描述符
Epoll::~Epoll() {
    close(epoll_fd); // 关闭 epoll 文件描述符
}