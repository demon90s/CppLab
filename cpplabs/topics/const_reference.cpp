// 常量引用
// 无论如何都不能通过常量引用修改其绑定的对象

#include <cassert>
#include <iostream>

int main()
{
    // 可以指向一个普通的对象
    int a = 42;
    const int &ra = a;

    // 可以指向一个常量
    const int b = 42;
    const int &rb = b;

    // 也可以指向一个临时值
    const int &rtmp = 42;
    const int &rtmp2 = 3.14;    // 隐式地将3.14转换成3
    assert(rtmp2 == 3);

    std::cout << "[TEST] const reference PASS\n";
}