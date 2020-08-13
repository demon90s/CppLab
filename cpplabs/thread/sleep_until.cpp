// sleep_until
// 挂起执行线程，直到到达一个 time_point

#include <thread>
#include <chrono>
#include <iostream>

time_t get_now_timestamp()
{
    auto tp = std::chrono::system_clock::now();
    return std::chrono::system_clock::to_time_t(tp);
}

void test_sleep_until()
{
    time_t to_timestamp = get_now_timestamp() + 5;
    auto to_tp = std::chrono::system_clock::from_time_t(to_timestamp);

    std::cout << "[" << get_now_timestamp() << "]" << "start to sleep for 5 seconds" << std::endl;
    std::this_thread::sleep_until(to_tp);
    std::cout << "[" << get_now_timestamp() << "]" << "done" << std::endl;
}

int main()
{
    test_sleep_until();
}