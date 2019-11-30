/*
    auto var = expr; 使用等号右边的表达式推导出变量的类型，并且会执行表达式

    decltype(expr) var; 使用其表达式的结果推导出其类型，而不会执行表达式

    两者的类型推导都是在编译期完成
*/

/*
    auto 适用场景
    - 迭代器
    - range for loop
    - 如果类型很长，并且很容易知道它是什么的时候
    - 模板编程中，尾置返回类型推导返回值
*/

#include <cstdio>
#include <iostream>

int make_int()
{
    printf("make_int called\n");
    return 42;
}

void test_auto()
{
    auto i = make_int();        // i 是 int
    printf("i: %d\n", i);
}

void test_decltype()
{
    decltype(make_int()) i;    // i 是 int
    i = 42;
    printf("i: %d\n", i);
}

// 返回类型是v的引用类型
template<typename P>
auto Print(P v) -> decltype(*v)
{
    std::cout << *v << std::endl;
    return *v; 
}

int main()
{
    //test_auto();
    //test_decltype();

    int a = 42;
    int &ra = Print(&a);
    std::cout << ra << std::endl;

    return 0;
}