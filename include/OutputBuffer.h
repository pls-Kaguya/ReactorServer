#pragma once
#include "Buffer.h"

// OutputBuffer 类继承自 Buffer 类，用于管理输出缓冲区
class OutputBuffer : public Buffer {
    public:
        // 构造函数，初始化读写索引
        OutputBuffer();
        
        // 析构函数
        ~OutputBuffer();
        

        
    private:
        size_t read_index; // 读索引
        size_t write_index; // 写索引
};