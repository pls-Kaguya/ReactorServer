#pragma once
#include <vector>
#include<sys/syscall.h>
#include <iostream>
#include <mutex>
#include <unistd.h>
#include <thread>
#include <queue>
#include <condition_variable>
#include <functional>
#include <future>
#include <atomic>

// 线程池类
class ThreadPool {
    public:
        // 构造函数，初始化线程池
        ThreadPool(int num);
        
        // 析构函数，停止所有线程
        ~ThreadPool();
        
        // 添加任务到任务队列
        void AddTask(std::function<void()> task);
        
        // 停止线程池
        void Stop();
        
    private:
        // 任务队列
        std::queue<std::function<void()>> task_queue;
        
        // 线程池
        std::vector<std::thread> thread_pool;
        
        // 互斥锁
        std::mutex mtx;
        
        // 条件变量
        std::condition_variable cv;
        
        // 停止标志
        std::atomic<bool> stop;
        
        // 线程函数
        void ThreadFunc();
};

