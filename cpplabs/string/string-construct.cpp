/*
 * 构造 string 的方法
 */

#include <string>
#include <iostream>
#include <cassert>

void default_construct()
{
    std::string s;
    assert(s == "");
}

void copy_construct()
{
    //std::string s = "Hello"; // 隐式转换
    std::string s("Hello");
    assert(s == "Hello");
}

void other_construct()
{
    // 其他的构造方法

    // s是cp指向的数组中前n个字符的拷贝
    {
        const char cp[] = "Hello world";
        std::string::size_type n = 5;
        std::string s(cp, n);

        assert(s == "Hello");

        std::string s2(cp, 0);
        assert(s2 == "");
    }

    // s是 string s2 从下标 pos2 开始的字符的拷贝。若 pos2 > s2.size()，构造函数的行为未定义
    {
        std::string s2 = "Hello world";
        std::string::size_type pos2 = 6;
        std::string s(s2, pos2);

        assert(s == "world");
    }

    // s是 string s2 从下标 pos2 开始 len2 个字符的拷贝。若 pos2 > s2.size() ，构造函数的行为未定义。
    // 不管 len2 的值是多少，构造函数至多拷贝 s2.size() - pos2 个字符。
    {
        std::string s2 = "Hello world";
        std::string::size_type pos2 = 1; // e
        std::string::size_type len2 = 4; // ello
        std::string s(s2, pos2, len2);

        assert(s == "ello");
    }
}

int main()
{
    default_construct();
    copy_construct();
    other_construct();

    std::cout << "[TEST] string construct PASS\n";
    return 0;
}
