// timed_mutex 提供超时的加锁方式
// lock unlock try_lock
// try_lock_for try_lock_until

#include <mutex>
#include <thread>
#include <chrono>
#include <iostream>

void test_timed_mutex()
{
    int shared_data = 0;
    std::timed_mutex shared_data_mutex;

    std::thread write_thread([&shared_data, &shared_data_mutex]()
    {
        // 一秒钟生产一次
        for (int i = 1; i <= 10; i++)
        {
            shared_data_mutex.lock();
            shared_data = i;
            shared_data_mutex.unlock();

            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    });

    std::thread read_thread([&shared_data, &shared_data_mutex]()
    {
        while (true)
        {
            if (shared_data_mutex.try_lock_for(std::chrono::milliseconds(10)))
            {
                if (shared_data != 0)
                {
                    std::cout << "read shared_data: " << shared_data << std::endl;

                    if (shared_data >= 10)
                    {
                        shared_data_mutex.unlock();
                        break;
                    }

                    shared_data = 0;    // consume
                }

                shared_data_mutex.unlock();
            }
        }
    });

    write_thread.join();
    read_thread.join();
}

int main()
{
    test_timed_mutex();
}