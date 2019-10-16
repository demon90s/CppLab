/*
    #include <chrono>
    std::chrono::system_clock
    系统的当前时间

    时间单位：
    1秒(seconds) = 1000毫秒(milliseconds)
    1毫秒(milliseconds) = 1000微秒(microseconds)
    1微秒(microseconds) = 1000纳秒(nanoseconds)

    关系：
    clock -> time_point -> duration

    duration.count() 获得流逝的时间（按某种单位表示）
*/

#include <ctime>
#include <chrono>
#include <iostream>

void test1()
{
    // 流逝精度(nanoseconds)
    std::cout <<
        std::chrono::system_clock::period::num << "/" <<
        std::chrono::system_clock::period::den << "\n"; // 1/1000000000
}

void show_time_str()
{
    time_t timestamp = 
        std::chrono::duration_cast<std::chrono::seconds>
            (std::chrono::system_clock::now().time_since_epoch()).count();

    tm *lt = localtime(&timestamp);

    char timestr[1024] {};
    strftime(timestr, sizeof(timestr), "%Y-%m-%d %H:%M:%S", lt);

    std::cout << timestr << std::endl;
}

int main()
{
    //test1();
    show_time_str();

    return 0;
}
