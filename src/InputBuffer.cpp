#include "InputBuffer.h"

// 构造函数，初始化读写索引并预分配缓冲区空间
InputBuffer::InputBuffer() : read_index(0), write_index(0) {
    buffer.resize(1024); // 预分配 1024 字节的缓冲区空间
}

// 析构函数
InputBuffer::~InputBuffer() {
    // 这里不需要显式释放资源，因为 std::string 会自动管理内存
}

// 获取指定长度的消息
std::string InputBuffer::GetMessage(int len) {
    if (len > buffer_size - read_index) {
        len = buffer_size - read_index; // 如果请求的长度超过可读数据长度，调整为可读数据长度
    }
    std::string message = buffer.substr(read_index, len); // 从缓冲区中提取指定长度的消息
    read_index += len; // 更新读索引
    return message;
}

// 获取所有消息
std::string InputBuffer::GetMessage() {
    std::string message = buffer.substr(read_index, buffer_size - read_index); // 提取所有未读消息
    read_index = buffer_size; // 更新读索引
    return message;
}
