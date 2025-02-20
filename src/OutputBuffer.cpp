#include"OutputBuffer.h"

OutputBuffer::OutputBuffer():read_index(0),write_index(0){
    buffer.resize(1024);
}
OutputBuffer::~OutputBuffer() {
}