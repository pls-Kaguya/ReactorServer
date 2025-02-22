#include "EventLoop.h"

// 构造函数，初始化 Epoll 实例
EventLoop::EventLoop() {
    ep = new Epoll();
}

// 运行事件循环
void EventLoop::Run() {
    std::cout << "create thread " << syscall(SYS_gettid) << std::endl;
    while (true) {
        std::vector<Channel *> channels;
        channels = ep->EventLoop(); // 等待事件发生

        if (channels.size() == 0) {
            // 如果没有事件发生，调用超时回调函数
            timeout_callback(this);
        } else {
            // 处理所有就绪的事件
            for (auto& ch : channels) {
                ch->EventHandle();
            }
        }
    }
}

// 获取 Epoll 实例
Epoll* EventLoop::GetEpoll() {
    return ep;
}

// 更新 Channel 对象的事件
void EventLoop::UpdateChannel(Channel *ch) {
    ep->UpdateChannel(ch);
}

// 从事件循环中移除 Channel 对象
void EventLoop::RemoveChannel(Channel* ch) {
    ep->RemoveChannel(ch);
}

// 设置超时回调函数
void EventLoop::SetTimeoutCallback(std::function<void(EventLoop*)> cb) {
    timeout_callback = cb;
}

// 析构函数，释放 Epoll 实例
EventLoop::~EventLoop() {
    delete ep;
}
