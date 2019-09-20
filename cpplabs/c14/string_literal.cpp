/*
#include <string>

std::literals::string_literals::operator""s

组成所欲类型的string字面量
*/

#include <string>
#include <iostream>

int main()
{
    using namespace std::literals::string_literals;

    std::string s = "abc\0\0efg\0\0"s;

    std::cout << s.size() << std::endl; // 10
    std::cout << s << std::endl;    // abcefg

    return 0;
}