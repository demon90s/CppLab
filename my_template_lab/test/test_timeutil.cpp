#include "../library/timeutil.hpp"
#include <iostream>

int main()
{
    auto sec = TimeUtil::SecondToNextTimePoint(TimeUtil::SecondTimePoint(10));
    std::cout << sec << std::endl;

    sec = TimeUtil::SecondToNextTimePoint(TimeUtil::MinuteTimePoint(45, 0));
    std::cout << sec << std::endl;

    // sec = TimeUtil::NextTimeInterval(34, 0);
    // std::cout << sec << std::endl;

    // sec = TimeUtil::NextTimeInterval(2, 0, 0);
    // std::cout << sec << std::endl;

    // sec = TimeUtil::NextWeekInterval(6, 0, 0, 0);
    // std::cout << sec << std::endl;

    // sec = TimeUtil::NextMonthInterval(25, 0, 0, 0);
    // std::cout << sec << std::endl;
}