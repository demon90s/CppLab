#include <list>
#include <cstring>
#include <iostream>

int GetMatchScore(const char *str1, const char *str2)
{
    // 1. 查子串
    // 2. 查第一个不匹配的位置
    if (strlen(str1) < strlen(str2))
    {
        std::swap(str1, str2);
    }

    std::string str1_str = str1;
    std::string str2_str = str2;
    if (str1_str.find(str2) != std::string::npos)
    {
        return static_cast<int>(strlen(str2));
    }

    std::list<char> str1_list, str2_list;

    const char *p1 = str1;
    while (*p1)
    {
        str1_list.push_back(*p1++);
    }

    const char *p2 = str2;
    while (*p2)
    {
        str2_list.push_back(*p2++);
    }

    auto diff_pair = std::mismatch(str1_list.begin(), str1_list.end(), str2_list.begin());
    int score1 = static_cast<int>(std::distance(str1_list.begin(), diff_pair.first));

    str1_list.reverse();
    str2_list.reverse();
    diff_pair = std::mismatch(str1_list.begin(), str1_list.end(), str2_list.begin());
    int score2 = static_cast<int>(std::distance(str1_list.begin(), diff_pair.first));

    return std::max(score1, score2);
}

int main()
{
    std::cout << GetMatchScore("printrolebaseinfo", "wudx") << std::endl;
}
