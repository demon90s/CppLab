/*
    #include <ratio>
    class ratio

    提供编译时有理数算术支持。
    
    NOTE：
    - 也代表了一种比率。比如时间单位。chrono::system_clock::period
*/

#include <chrono>
#include <iostream>

int main()
{
    std::ratio<1, 10> r;
    std::cout << r.num << "/" << r.den << std::endl;    // 1/10

    std::ratio<2, 10> r2;
    std::cout << r2.num << "/" << r2.den << std::endl;  // 1/5

    return 0;
}