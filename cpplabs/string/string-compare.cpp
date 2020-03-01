/*
    std::string::compare

    s.compare(arg)
    比较s和 arg 所代表的字符串，大于 arg 返回正数，等于返回0，小于返回负数。
*/

#include <string>
#include <iostream>
#include <cassert>

void Test1()
{
    std::string s = "ABC";

    assert(s.compare("ABD") < 0);
    assert(s.compare("ABB") > 0);
    assert(s.compare("ABC") == 0);
}

int main()
{
    Test1();
    std::cout << "[TEST] string::compare PASS\n";
    return 0;
}