/*
    user defined literal

    literal是一种常量

    C++支持四种literal：
    - integer 42
    - floating point 3.14
    - character 'z'
    - string "Dog"

    user defined literal 重载函数支持这几种参数类型：
    const char*
    unsigned long long
    long double
    const char*, std::size_t

    但返回类型可以是任意的
*/

#include <iostream>

constexpr long double operator"" _cm(long double x) { return x / 1000; }
constexpr long double operator"" _m(long double x) { return x; }
constexpr long double operator"" _km(long double x) { return 1000 * x; }

// 得到字符串长度
constexpr int operator"" _len(const char *bin_str, std::size_t len)
{
    return static_cast<int>(len);
}

int main()
{
    double x = 1.3_m;
    std::cout << x << std::endl;        // 1.3

    x = 1.3_cm;
    std::cout << x << std::endl;        // 0.0013

    x = 1.3_km;
    std::cout << x << std::endl;        // 1300

    std::cout << "hello"_len << std::endl;  // 5
}
