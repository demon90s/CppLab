/*
    #include <mutex>
    使用RAII管理一个 mutex，在初始化的时候，lock住
    确保即使出现异常，也能正确unlock
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <stdexcept>

std::mutex mtx;

void work_func(int i)
{
    // std::cout 是全局共享资源，要加锁
    // 否则，输出就是mess
    std::lock_guard<std::mutex> lck(mtx);
    std::cout << "thread " << i << " running\n";
}

int main()
{
    std::thread t_list[10];

    // spawn 10 thread
    for (size_t i = 0; i < std::size(t_list); i++)
    {
        t_list[i] = std::thread(work_func, i);
    }
    
    // join them
    for (auto &t : t_list)
    {
        t.join();
    }

    return 0;
}