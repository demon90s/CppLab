/*
    #include <mutex>

    一种可以移动的 lock guard，并且使用更加灵活的方式管理 mutex。。
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

    std::unique_lock<std::mutex> lck(mtx);

    // 若使用 defer_lock ，默认不自动加锁
    //std::unique_lock<std::mutex> lck(mtx, std::defer_lock);
    //lck.lock();
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