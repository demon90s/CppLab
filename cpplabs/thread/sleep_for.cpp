/*
    std::this_thread::sleep_for(duration)

    阻塞当前线程执行, 至少经过指定的 duration 时间
*/

#include <thread>
#include <chrono>
#include <iostream>

void test1()
{
    auto duration = std::chrono::milliseconds(1000);    // 1s

    while (true) {
        auto now_timepoint = std::chrono::system_clock::now();
        time_t timestamp = std::chrono::system_clock::to_time_t(now_timepoint);

        std::cout << "[" << timestamp << "]" << "hello~~~we will sleep for 1 second" << std::endl;
        std::this_thread::sleep_for(duration);
    }
}

int main()
{
    test1();

    return 0;
}