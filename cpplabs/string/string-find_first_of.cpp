/*
    std::string::find_first_of

    s.find_first_of(args)
    在s中查找 args 中任何一个字符第一次出现的位置

    可以设置一个查找起始位置作为第二个参数
*/

#include <string>
#include <iostream>
#include <cassert>

void Test1()
{
    std::string s = "ABCDEFGHIJK";

    auto pos = s.find_first_of("EGI");
    assert(pos == 4);
}

void Test2()
{
    std::string s = "a1b2c3ddd987";
    std::string numbers = {"0123456789"};

    auto pos = s.find_first_of(numbers, 4);
    assert(pos == 5);
}

int main()
{
    Test1();
    Test2();

    std::cout << "[TEST] string::find_first_of PASS\n";

    return 0;
}