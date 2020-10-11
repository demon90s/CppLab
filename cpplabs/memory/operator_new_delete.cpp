#include "operator_new_delete.h"
#include <vector>

void Test1()
{
    char *cp = new char('A');
    delete cp;

    char *carr = new char[12] {};
    delete[] carr;
}

void Test2()
{
    Foo *foo = new Foo();
    delete foo;

    std::cout << "test for vector\n";
    std::vector<Foo> foo_vec; // 这里调用的是全局的版本
    foo_vec.resize(1);
}

// 测试 operator new[] 后，编译器把数组的长度存放的位置
// 通常，比如在 Ubuntu18.04 上，存放在数组首元素的前一个位置（前8个字节）
// 这是由实现决定的，总之如果使用了 operator new[] 申请内存，那么就必须用 operator delete[] 释放内存
// 参考： Effective C++ 条款16
void Test3()
{
    static const int SZ = 15;
    auto p = new Foo[SZ] {};

    std::cout << *((long*)p - 1) << std::endl;

    delete[] p;
}

// 如果创建的是派生类的动态对象，也会去查询基类的动态分配方法，并使用之
void Test4()
{
    Bar *b = new Bar();
    delete b;
}

int main()
{
    //Test1();
    Test2();
    //Test3();
    //Test4();

    return 0;
}