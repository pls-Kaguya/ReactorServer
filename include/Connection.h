#pragma once
#include"Channel.h"
#include"InputBuffer.h"
#include"OutputBuffer.h"

class Connection{
    private:
        Channel *connection_channel;
        EventLoop *loop;
        Socket *client_socket;
        InputBuffer input_buffer;
        OutputBuffer output_buffer;
        std::function<void(Connection*)> close_callback;
        std::function<void(Connection*)> error_callback;
        std::function<void(Connection*)> read_callback;
        std::function<void(Connection*)> write_callback;
    public:
        Connection(EventLoop* loop,Socket *socket);
        void EnableReading();
        void EnableWriting();
        void DisableWriting();
        void Send(const std::string& message);
        void Send(const char* message);
        void Send(const void* message, size_t len);
        void HandleRead();
        void HandleWrite();
        void HandleError();
        void HandleClose();
        int GetFd();
        void SetCloseCallback(std::function<void(Connection*)> cb);
        void SetErrorCallback(std::function<void(Connection*)> cb);
        void SetReadCallback(std::function<void(Connection*)> cb);
        void SetWriteCallback(std::function<void(Connection*)> cb);
        ~Connection();
};