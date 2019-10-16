/*
    #include <chrono>
    std::chrono::system_clock
    系统的当前时间

    时间单位：
    1秒(seconds) = 1000毫秒(milliseconds)
    1毫秒(milliseconds) = 1000微秒(microseconds)
    1微秒(microseconds) = 1000纳秒(nanoseconds)
*/

#include <chrono>
#include <iostream>

int main()
{
    // 流逝精度(nanoseconds)
    std::cout <<
        std::chrono::system_clock::period::num << "/" <<
        std::chrono::system_clock::period::den << "\n"; // 1/1000000000

    return 0;
}
