/*
    #include <chrono>
    std::chrono::time_point

    一个时间点。

    系统时间（system_clock）从UTC开始。
*/

#include <chrono>
#include <iostream>

void test_system_clock()
{
    // current time of system clock
    std::chrono::system_clock::time_point tp = std::chrono::system_clock::now();

    std::cout << tp.time_since_epoch().count() << std::endl;    // the unit is nanoseconds

    auto timestamp = std::chrono::duration_cast<std::chrono::seconds>(tp.time_since_epoch());
    std::cout << timestamp.count() << std::endl;    // seconds from utc
}

void test_steady_clock()
{
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

    std::cout << "run test steady clock, check duration...\n";

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    auto duration = end - start;
    std::cout << "duration: " << duration.count() << "(nanoseconds)\n";

    auto duration_micro = std::chrono::duration_cast<std::chrono::microseconds>(duration);
    std::cout << "duration: " << duration_micro.count() << "(microseconds)\n";
}

int main()
{
    test_system_clock();

    test_steady_clock();

    return 0;
}