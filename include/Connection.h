#pragma once
#include "Channel.h"
#include "InputBuffer.h"
#include "OutputBuffer.h"
#include <string>
#include <memory>
#include <atomic>
#include <functional>

// 前向声明 Connection 类
class Connection;

// 使用 shared_ptr 管理 Connection 实例
using spConnection = std::shared_ptr<Connection>;

// Connection 类用于管理客户端连接
class Connection : public std::enable_shared_from_this<Connection> {
    private:
        // 管理连接的 Channel 实例，使用 unique_ptr 管理
        upChannel connection_channel;
        
        // 事件循环
        EventLoop* loop;
        
        // 客户端套接字，使用 unique_ptr 管理
        upSocket client_socket;
        
        // 输入缓冲区
        InputBuffer input_buffer;
        
        // 输出缓冲区
        OutputBuffer output_buffer;
        
        // 连接是否断开
        std::atomic_bool disconnected;
        
        // 关闭回调函数
        std::function<void(spConnection)> close_callback;
        
        // 错误回调函数
        std::function<void(spConnection)> error_callback;
        
        // 读回调函数
        std::function<void(spConnection, std::string&)> read_callback;
        
        // 写回调函数
        std::function<void(spConnection)> write_callback;
    public:
        // 构造函数，初始化事件循环和客户端套接字
        Connection(EventLoop* loop, upSocket socket);
        
        // 启用读事件
        void EnableReading();
        
        // 启用写事件
        void EnableWriting();
        
        // 禁用写事件
        void DisableWriting();
        
        // 发送字符串消息
        void Send(const std::string& message);
        
        // 发送字符数组消息
        void Send(const char* message);
        
        // 发送任意类型消息
        void Send(const void* message, size_t len);
        
        // 处理读事件
        void HandleRead();
        
        // 处理写事件
        void HandleWrite();
        
        // 处理错误事件
        void HandleError();
        
        // 处理关闭事件
        void HandleClose();
        
        // 获取文件描述符
        int GetFd();
        
        // 设置关闭回调函数
        void SetCloseCallback(std::function<void(spConnection)> cb);
        
        // 设置错误回调函数
        void SetErrorCallback(std::function<void(spConnection)> cb);
        
        // 设置读回调函数
        void SetReadCallback(std::function<void(spConnection, std::string&)> cb);
        
        // 设置写回调函数
        void SetWriteCallback(std::function<void(spConnection)> cb);
        
        // 析构函数
        ~Connection();
};