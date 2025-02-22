#pragma once

#include <string>
#include <iostream>

// Buffer 类用于管理缓冲区数据
class Buffer {
    private:
        // 存储缓冲区数据的字符串
        std::string buffer;
        
        // 缓冲区大小
        size_t buffer_size;
    public:
        // 构造函数
        Buffer();
        
        // 析构函数
        ~Buffer();
        
        // 追加字符串数据到缓冲区
        void Append(const std::string& data);
        
        // 追加字符数组数据到缓冲区
        void Append(const char* data, size_t len);
        
        // 追加任意类型数据到缓冲区
        void Append(const void* data, size_t len);
        
        // 追加带有头部长度信息的数据到缓冲区
        void AppendWithHeader(const std::string& data, size_t len);
        
        // 获取缓冲区数据大小
        size_t Size();
        
        // 获取缓冲区数据指针
        const char* Data();
        
        // 清空缓冲区
        void Clear();
        
        // 从缓冲区中删除指定位置和长度的数据
        void Erase(size_t pos, size_t len);
        
        // 获取缓冲区中的消息
        std::string GetMessage();
};