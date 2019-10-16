/*
    #include <chrono>
    std::chrono::time_point

    一个时间点。

    系统时间（system_clock）从UTC开始。
*/

#include <chrono>
#include <iostream>

int main()
{
    // current time of system clock
    std::chrono::system_clock::time_point tp = std::chrono::system_clock::now();

    std::cout << tp.time_since_epoch().count() << std::endl;    // the unit is nanoseconds

    auto timestamp = std::chrono::duration_cast<std::chrono::seconds>(tp.time_since_epoch());
    std::cout << timestamp.count() << std::endl;    // seconds from utc

    return 0;
}