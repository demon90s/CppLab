/*
    std::string::find_last_not_of

    s.find_last_not_of(args)
    在s中查找最后一个不在 args 中的字符
*/

#include <string>
#include <iostream>
#include <cassert>

void Test1()
{
    std::string s = "ABCDEFGHIJK";

    auto pos = s.find_last_not_of("ABC");
    assert(pos == 10);

    pos = s.find_last_not_of("JK");
    assert(pos == 8);
}

int main()
{
    Test1();
    std::cout << "[TEST] string::find_last_not_of PASS\n";
    return 0;
}