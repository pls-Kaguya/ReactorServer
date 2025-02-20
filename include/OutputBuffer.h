#pragma once
#include"Buffer.h"

class InputBuffer:Buffer{
    public:
        InputBuffer();
        ~InputBuffer();
    private:
        size_t read_index;
        size_t write_index;
};