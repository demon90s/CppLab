/*
    正则表达式库
    #include <regex>

    regex_match(str, res)   -- str是否和res匹配
    regex_search(str, res)  -- res是否能匹配成str的子串
*/

#include <regex>
#include <iostream>
#include <string>

int main()
{
    std::string str;

    while (std::cin >> str)
    {
        //std::regex re("abc");               // only 'abc' matched
        //std::regex re("abc", std::regex_constants::icase);  // 大小写不敏感，‘aBc’ 也能match
        //std::regex re("abc.");              // . 表示任意一个字符，但不包括换行  如： 'abcX' matched
        //std::regex re("abc?");              // ? 表示0个或1个？前的字符，如 'ab' 和 'abc' 都 match，其他不行
        //std::regex re("abc*");              // * 表示0个或多个*前的字符，如'ab' 和 'abccc' 都 match
        //std::regex re("abc+");              // + 表示1个或多个+前的字符，如 'abc' 和 ‘abccc’ 都 match
        //std::regex re("ab[cd]*");           // [...] 表示括号中的任意1个字符，如 'ab' ‘abc’ ‘abcd’ 都 match
        //std::regex re("ab[^cd]*");          // [^,,,] 表示任意一个不是括号中所有字符的字符
        std::regex re("ab[cd]{3}");          // {n} 表示前面的字符出现n次

        bool match = std::regex_match(str, re);
        std::cout << (match ? "match" : "not match") << std::endl;
    }
}