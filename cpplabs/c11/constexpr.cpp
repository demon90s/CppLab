/*
    关键字 constexpr

    自C++11起， constexpr 可用来让表达式核定于编译期。
*/

#include <iostream>
#include <cassert>

constexpr int square(int x)
{
    return x * x;
}

int global_i = 42;

int main()
{
    float a[square(9)];     // OK, 编译期就可以计算得到a有81个元素
    std::cout << sizeof(a) / sizeof(a[0]) << std::endl; // 81

    static_assert(square(9) == 81, "of course ok");

    // constexpr 可以修饰一个指针变量，此时其效果绝对是顶层的常量
    // 但是这个指针必须有固定地址（或者nullptr），local变量不符合这个要求
    constexpr int *pi = &global_i;
    *pi = 100;
    assert(global_i == 100);
    //pa = nullptr; // 指针本身不可修改

    return 0;
}
