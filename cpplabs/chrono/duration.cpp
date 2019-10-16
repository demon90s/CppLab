/*
    #include <chrono>
    duration

    表示时间流失的长度，第二个模板参数表示时间单位

    duration<int, ratio<1, 1>> 是用int表示的秒
    duration<double, ratio<60, 1>> 是用double表示的分钟
    duration<double, ratio<1, 1000>> 是用double表示的毫秒

    已定义的duration:
    nanoseconds, microseconds, milliseconds, seconds, minutes, hours
*/

#include <chrono>
#include <thread>
#include <iostream>

void test()
{
    //auto sleep_duration = std::chrono::seconds(1);

    /*
    using custom_dur = std::chrono::duration<int, std::ratio<3, 1>>;     // 3秒一个dur
    auto sleep_duration = custom_dur(1);  // 3秒
    */

    using custom_dur = std::chrono::duration<double, std::ratio<1, 1000>>;  // 1毫秒一个dur
    auto sleep_duration = custom_dur(300); // 300毫秒

    for (int i = 0; i < 5; i++)
    {
        std::cout << "For Loop ...\n";
        std::this_thread::sleep_for(sleep_duration);
    }
}

void test_duration_cast()
{
    std::chrono::milliseconds ms(1600);

    // 毫秒 -> 秒，精度会损失，因此需要强制转换 trunc not round
    std::chrono::seconds s = std::chrono::duration_cast<std::chrono::seconds>(ms);

    std::cout << s.count() << std::endl;    // 1

    // 不需要转换，秒 -> 毫秒
    ms = ms + s;
    std::cout << ms.count() << std::endl;   // 2600
}

int main()
{
    //test();

    test_duration_cast();

    return 0;
}