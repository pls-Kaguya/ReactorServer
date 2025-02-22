#include "ThreadPool.h"
#include <sys/syscall.h> // 添加此行以包含 SYS_gettid 所需的头文件

// 构造函数，初始化线程池
ThreadPool::ThreadPool(int num,int type) : stop(false),type(type) {
    for (int i = 0; i < num; i++) {
        // 创建线程并将其添加到线程池
        thread_pool.emplace_back([this] {
            std::cout << "create thread " << syscall(SYS_gettid) << std::endl;
            while (!stop) {
                std::function<void()> task;
                { // lock作用域开始
                    std::unique_lock<std::mutex> lock(this->mtx);
                    // 等待任务或停止信号
                    this->cv.wait(lock, [this] {
                        return stop || !task_queue.empty();
                    });
                    // 如果停止且任务队列为空，退出线程
                    if (stop && task_queue.empty()) {
                        return;
                    }
                    // 从任务队列中取出任务
                    task = std::move(task_queue.front());
                    task_queue.pop();
                }
                // 执行任务
                std::cout << "create thread " << syscall(SYS_gettid) << std::endl;
                task();
            }
        });
    }
}

// 添加任务到任务队列
void ThreadPool::AddTask(std::function<void()> task) {
    {
        std::unique_lock<std::mutex> lock(mtx);
        task_queue.push(task);
    }
    // 通知一个等待的线程
    cv.notify_one();
}

// 停止线程池
void ThreadPool::Stop() {
    {
        std::unique_lock<std::mutex> lock(mtx);
        stop = true;
    }
    // 通知所有等待的线程
    cv.notify_all();
    // 等待所有线程完成
    for (std::thread &thread : thread_pool) {
        if (thread.joinable()) {
            thread.join();
        }
    }
}

// 析构函数，停止所有线程
ThreadPool::~ThreadPool() {
    Stop();
}