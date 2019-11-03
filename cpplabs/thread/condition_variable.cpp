/*
    #include <condition_variable>

    条件变量可以用于解决 buzy waiting 的问题。

    buzy waiting 是一个线程中的 while loop，为了节约cpu，可以使用
    条件变量阻塞住，再在合适的时机解除阻塞。
*/

#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>
#include <list>

std::list<int> msg_list;
std::mutex mtx;
std::condition_variable cond;

void producer()
{
    for (int i = 10; i >= 1; i--)
    {
        std::unique_lock<std::mutex> lck(mtx);
        msg_list.push_back(i);
        lck.unlock();
        cond.notify_one();
    }
}

void consumer()
{
    int data = 0;
    while (data != 1)
    {
        std::unique_lock<std::mutex> lck(mtx);
        if (msg_list.size() == 0)
        {
            cond.wait(lck); // 1. unlock mtx 2. wait 3. be notified then lock mtx
            //当被notify后, 若谓词不满足，继续重新wait
            //cond.wait(lck, [](){ return msg_list.size() > 0; });
        }
        
        data = msg_list.front();
        msg_list.pop_front();
        lck.unlock();
        std::cout << data << std::endl;
    }
}

int main()
{
    std::thread pro_t(producer);
    std::thread con_t(consumer);

    pro_t.join();
    con_t.join();

    return 0;
}