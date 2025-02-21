#pragma once

#include<string>
#include<iostream>
class Buffer{
    private:
        std::string buffer;
        size_t buffer_size;
    public:
        Buffer();
        ~Buffer();
        void Append(const std::string& data);
        void Append(const char* data, size_t len);
        void Append(const void* data, size_t len);
        void AppendWithHeader(const std::string& data,size_t len);
        size_t Size();
        const char* Data();
        void Clear();
        void Erase(size_t pos,size_t len);
        std::string GetMessage();
};