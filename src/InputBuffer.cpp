#include"InputBuffer.h"

InputBuffer::InputBuffer():read_index(0),write_index(0){
    buffer.resize(1024);
}
InputBuffer::~InputBuffer() {
}
