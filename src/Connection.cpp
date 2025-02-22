#include "Connection.h"

// 构造函数，初始化事件循环和客户端套接字
Connection::Connection(EventLoop* loop, upSocket socket)
    : loop(loop), client_socket(std::move(socket)), disconnected(false) {
    // 创建 Channel 实例并设置回调函数
    connection_channel = std::make_unique<Channel>(loop, client_socket->GetFd(), false);
    connection_channel->SetReadCallback(std::bind(&Connection::HandleRead, this));
    connection_channel->SetWriteCallback(std::bind(&Connection::HandleWrite, this));
    connection_channel->SetErrorCallback(std::bind(&Connection::HandleError, this));
    connection_channel->SetCloseCallback(std::bind(&Connection::HandleClose, this));
    connection_channel->SetEt(); // 设置边缘触发
    connection_channel->EnableReading(); // 启用读事件
}

// 获取文件描述符
int Connection::GetFd() {
    return connection_channel->GetFd();
}

// 启用读事件
void Connection::EnableReading() {
    connection_channel->EnableReading();
}

// 启用写事件
void Connection::EnableWriting() {
    connection_channel->EnableWriting();
}

// 禁用写事件
void Connection::DisableWriting() {
    connection_channel->DisableWriting();
}

// 发送字符串消息
void Connection::Send(const std::string& message) {
    if (disconnected) return; // 如果连接已断开，直接返回
    output_buffer.Append(message); // 将消息追加到输出缓冲区
    EnableWriting(); // 启用写事件
}

// 发送字符数组消息
void Connection::Send(const char* message) {
    if (disconnected) return; // 如果连接已断开，直接返回
    output_buffer.Append(message); // 将消息追加到输出缓冲区
    EnableWriting(); // 启用写事件
}

// 发送任意类型消息
void Connection::Send(const void* message, size_t len) {
    if(disconnected) return; // 如果连接已断开，直接返回
    output_buffer.AppendWithHead(message, len); // 将消息追加到输出缓冲区，并附加头部长度信息
    EnableWriting(); // 启用写事件
}

// 处理读事件
void Connection::HandleRead() {
    char buffer[2048]; // 临时缓冲区
    memset(buffer, 0, sizeof(buffer)); // 清空缓冲区
    ssize_t readn;

    while (true) {
        readn = recv(GetFd(), buffer, sizeof(buffer), 0); // 从套接字读取数据
        if (readn > 0) {
            input_buffer.Append(buffer, readn); // 将读取的数据追加到输入缓冲区
        } else if (readn == 0) {
            HandleClose(); // 处理关闭事件
            break;
        } else if (readn == -1 && errno == EINTR) {
            continue; // 如果被信号中断，继续读取
        } else if ((readn == -1) && (errno == EAGAIN || errno == EWOULDBLOCK)) {
            //数据读取完毕
            while (true) {
                int len;
                memcpy(&len, input_buffer.Data(), sizeof(int)); // 从输入缓冲区读取消息长度
                if (input_buffer.Size() < len + sizeof(int)) {
                    break; // 如果缓冲区中的数据不足，退出循环
                }
                std::string message(input_buffer.Data() + sizeof(int), len); // 从缓冲区中提取消息
                input_buffer.Erase(0, len + sizeof(int)); // 从缓冲区中删除已处理的数据
                std::cout << "recv(client==" << GetFd() << ") message==" << message << std::endl;
                read_callback(shared_from_this(), message); // 调用读回调函数
            }
            break;
        } else {
            HandleError(); // 处理错误事件
            break;
        }
    }
}

// 处理写事件
void Connection::HandleWrite() {
    ssize_t write = send(GetFd(), output_buffer.Data(), output_buffer.Size(), 0); // 向套接字写入数据
    if (write > 0) {
        output_buffer.Erase(0, write); // 从输出缓冲区中删除已写入的数据
    }
    if (output_buffer.Size() == 0) {
        DisableWriting(); // 如果输出缓冲区为空，禁用写事件
        if (write_callback) {
            write_callback(shared_from_this()); // 调用写回调函数
        }
    }
}

// 处理错误事件
void Connection::HandleError() {
    disconnected = true; // 标记连接已断开
    connection_channel->Remove(); // 从事件循环中移除 Channel
    if (error_callback) {
        error_callback(shared_from_this()); // 调用错误回调函数
    }
}

// 处理关闭事件
void Connection::HandleClose() {
    disconnected = true; // 标记连接已断开
    connection_channel->Remove(); // 从事件循环中移除 Channel
    if (close_callback) {
        close_callback(shared_from_this()); // 调用关闭回调函数
    }
}

// 设置关闭回调函数
void Connection::SetCloseCallback(std::function<void(spConnection)> cb) {
    close_callback = cb;
}

// 设置错误回调函数
void Connection::SetErrorCallback(std::function<void(spConnection)> cb) {
    error_callback = cb;
}

// 设置读回调函数
void Connection::SetReadCallback(std::function<void(spConnection, std::string&)> cb) {
    read_callback = cb;
}

// 设置写回调函数
void Connection::SetWriteCallback(std::function<void(spConnection)> cb) {
    write_callback = cb;
}

// 析构函数
Connection::~Connection() {
    // unique_ptr 会自动释放资源
}