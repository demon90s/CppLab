/*
    std::string::find_first_not_of

    s.find_first_not_of(args)
    在s中查找第一个不在 args 中的字符
*/

#include <string>
#include <iostream>
#include <cassert>

void Test1()
{
    std::string s = "ABCDEFGHIJK";

    auto pos = s.find_first_not_of("ABC");
    assert(pos == 3);
}
    

int main()
{
    Test1();

    std::cout << "[TEST] string::find_first_not_of PASS\n";
    return 0;
}