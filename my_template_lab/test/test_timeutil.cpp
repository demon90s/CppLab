#include "../library/timeutil.hpp"
#include <iostream>

void test1()
{
    auto sec = timeutil::SecondToNextTimePoint(timeutil::SecondTimePoint(10));
    std::cout << sec << std::endl;

    sec = timeutil::SecondToNextTimePoint(timeutil::MinuteTimePoint(45, 0));
    std::cout << sec << std::endl;
}

void test2()
{
    timeutil::Timestamp t(time(NULL));
    std::cout << t.AscTime() << std::endl;

    std::cout << static_cast<long long>(t) << std::endl;
}

int main()
{
    test2();
}