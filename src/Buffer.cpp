#include "Buffer.h"

// 构造函数，初始化缓冲区大小并预分配空间
Buffer::Buffer() : buffer_size(0) {
    buffer.resize(1024);
}

// 追加字符串数据到缓冲区
void Buffer::Append(const std::string& data) {
    buffer.append(data);
    buffer_size += data.size();
}

// 追加字符数组数据到缓冲区
void Buffer::Append(const char* data, size_t len) {
    buffer.append(data, len);
    buffer_size += len;
}

// 追加任意类型数据到缓冲区
void Buffer::Append(const void* data, size_t len) {
    buffer.append(static_cast<const char*>(data), len);
    buffer_size += len;
}

// 追加带有头部长度信息的数据到缓冲区
void Buffer::AppendWithHeader(const std::string& data, size_t len) {
    buffer.append(reinterpret_cast<const char*>(&len), sizeof(int));
    buffer.append(data);
    buffer_size += len;
}

// 获取缓冲区数据大小
size_t Buffer::Size() {
    return buffer_size;
}

// 获取缓冲区数据指针
const char* Buffer::Data() {
    return buffer.c_str();
}

// 清空缓冲区
void Buffer::Clear() {
    buffer.clear();
    buffer_size = 0;
}

// 从缓冲区中删除指定位置和长度的数据
void Buffer::Erase(size_t pos, size_t len) {
    buffer.erase(pos, len);
    buffer_size -= len;
}

// 析构函数
Buffer::~Buffer() {
}
