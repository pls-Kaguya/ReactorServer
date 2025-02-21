#include"Buffer.h"

Buffer::Buffer():buffer_size(0){
    buffer.resize(1024);
}
void Buffer::Append(const std::string& data){
    buffer.append(data);
    buffer_size += data.size();
}
void Buffer::Append(const char* data, size_t len){
    buffer.append(data,len);
    buffer_size += len;
}
void Buffer::Append(const void* data, size_t len){
    buffer.append(static_cast<const char*>(data),len);
    buffer_size += len;
}
void Buffer::AppendWithHeader(const std::string& data,size_t len){
    buffer.append((char*)&len,sizeof(int));
    buffer.append(data);
    buffer_size += len;
    
}
size_t Buffer::Size(){
    return buffer_size;
}
const char* Buffer::Data(){
    return buffer.c_str();
}
void Buffer::Clear(){
    buffer.clear();
    buffer_size = 0;
}
void Buffer::Erase(size_t pos,size_t len){
    buffer.erase(pos,len);
    buffer_size -= len;
}
Buffer::~Buffer() {
}
