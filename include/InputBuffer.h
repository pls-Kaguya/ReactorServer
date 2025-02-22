#pragma once 

#include "Buffer.h"

// 前向声明 Buffer 类
class Buffer;

// InputBuffer 类继承自 Buffer 类，用于管理输入缓冲区
class InputBuffer : public Buffer {
    public:
        // 构造函数，初始化读写索引
        InputBuffer();
        
        // 析构函数
        ~InputBuffer();
        
        // 获取指定长度的消息
        std::string GetMessage(int len);
        
        // 获取所有消息
        std::string GetMessage();
    private:
        size_t read_index; // 读索引
        size_t write_index; // 写索引
};