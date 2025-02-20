#include"EventLoop.h"

/*

class EventLoop{
    private:
        Epoll *ep;
    public:
        EventLoop();
        void Run();
        ~EventLoop();
};*/
EventLoop::EventLoop(){
    ep = new Epoll();
}
void EventLoop::Run(){
    while(true){
        std::vector<Channel *> channels;
        channels = ep->EventLoop();
        if(channels.size()==0){
            timeout_callback(this);
        }else{
            for(auto&ch:channels){
                ch->EventHandle();
            }
        } 
    }
}
Epoll* EventLoop::GetEpoll(){
    return ep;
}
void EventLoop::UpdateChannel(Channel *ch){
    ep->UpdateChannel(ch);
}
void EventLoop::SetTimeoutCallback(std::function<void(EventLoop*)> cb){
    timeout_callback = cb;
}
EventLoop::~EventLoop(){
    delete ep;
}
