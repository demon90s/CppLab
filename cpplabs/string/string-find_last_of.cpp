/*
    std::string::find_last_of

    s.find_last_of(args)
    在s中查找 args 中任何一个字符最后一次出现的位置
*/

#include <string>
#include <iostream>
#include <cassert>

void Test1()
{
    std::string s = "ABCDEFGHIJK";

    auto pos = s.find_last_of("EGI");
    assert(pos == 8);

    pos = s.find_last_of("123");
    assert(pos == std::string::npos);
}

int main()
{
    Test1();
    std::cout << "[TEST] string::find_last_of PASS\n";
    return 0;
}