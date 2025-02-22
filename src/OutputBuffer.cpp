#include "OutputBuffer.h"

// 构造函数，初始化读写索引并预分配缓冲区空间
OutputBuffer::OutputBuffer() : read_index(0), write_index(0) {
    buffer.resize(1024); // 预分配 1024 字节的缓冲区空间
}

// 析构函数
OutputBuffer::~OutputBuffer() {
    // 这里不需要显式释放资源，因为 std::string 会自动管理内存
}
