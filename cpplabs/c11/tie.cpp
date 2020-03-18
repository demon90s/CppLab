#include <tuple>
#include <iostream>
#include <cassert>

// #include <tuple>
// std::tie<args&...>
// 得到一个绑定左值引用的 tuple
// 可以用于处理多重返回值

std::tuple<int, double> foo()
{
    return std::tuple<int, double>(42, 3.14);
}

int main()
{
    int a;
    double d;

    std::tie(a, d) = foo();

    assert(a == 42);
    assert(d == 3.14);

    // 可以忽略掉某个返回值，使用 std::ignore
    d = 0;
    std:tie(std::ignore, d) = foo();
    assert(d == 3.14);

    std::cout << "[TEST] std::tie PASS\n";
}