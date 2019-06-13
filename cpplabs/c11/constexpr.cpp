/*
    关键字 constexpr

    自C++11起， constexpr 可用来让表达式核定于编译期。
*/

#include <iostream>

constexpr int square(int x)
{
    return x * x;
}

int main()
{
    float a[square(9)];     // OK, 编译期就可以计算得到a有81个元素
    std::cout << sizeof(a) / sizeof(a[0]) << std::endl; // 81

    return 0;
}
