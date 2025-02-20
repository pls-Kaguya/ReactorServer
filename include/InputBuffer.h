#pragma once 

#include"Buffer.h"
class Buffer;

class InputBuffer:Buffer{
    public:
        InputBuffer();
        ~InputBuffer();
        std::string GetMessage(int len);
        std::string GetMessage();
    private:
        size_t read_index;
        size_t write_index;
};