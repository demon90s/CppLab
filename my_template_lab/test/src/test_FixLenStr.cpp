#include "../library/FixLenStr.hpp"
#include <iostream>

/*
int main()
{
    FixLenStr<32> str = "hello";
    std::cout << str << std::endl;

    char raw[32];
    str.Copy(raw);
    std::cout << raw << std::endl;

    const char *raw_str = str;
    std::cout << raw_str << std::endl;

    std::string s = str;
    std::cout << s << std::endl;

    FixLenStr<5> str2 = s;
    std::cout << str2 << std::endl;

    str2 = s;
    str2 = "wowaaaaaaaaaaa";
    std::cout << str2 << std::endl;

    str = str;
    std::cout << str << std::endl;

    str = str.Data();
    std::cout << str << std::endl;

    std::cout << str.Len() << std::endl;
}
*/