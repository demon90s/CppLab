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
#include <cassert>
#include <iostream>

int make_int(){
    assert(false);              // 但我不会被调用
    return 42;
}

void test_decltype()
{
    decltype(make_int()) i;    // i 是 int, make_int函数不会被调用
    i = 42;
    assert(i == 42);

    // 如果给变量加上一对括号( 即 decltype((v)) )，decltype的结果一定是引用
    decltype((i)) ri = i;
    ri = 100;
    assert(i == 100);
}

// 返回类型是v的引用类型
template<typename P>
auto Pow(P v) -> decltype(*v)
{
    *v = *v * *v;
    return *v; 
}

int main()
{
    test_decltype();

    int a = 2;
    int &ra = Pow(&a);
    
    assert(ra == 4);
    assert(a == 4);

    std::cout << "[TEST] decltype PASS\n";

    return 0;
}