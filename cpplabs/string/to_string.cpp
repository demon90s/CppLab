/*
    std::to_string

    to_string(val) 返回数值 val 的 string 表示。
    val 可以是任何算数类型。
*/

#include <string>
#include <iostream>
#include <cassert>

void Test1()
{
    assert(std::to_string(42) == "42");
    assert(std::to_string(3.14) == "3.140000");
}

int main()
{
    Test1();

    std::cout << "[TEST] to_string PASS\n";

    return 0;
}