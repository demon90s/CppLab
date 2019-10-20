#include <iostream>
#include <map>

int main()
{
    std::multimap<std::string, std::string> author = 
    {
        {"朱光潜", "给青年的十二封信"},
        {"朱光潜", "谈美"},
        {"梁漱溟", "中国文化要义"},
        {"梁漱溟", "人心与人生"},
    };

    // equal_range，返回一个pair，表明等于key的元素范围
    auto range = author.equal_range("梁漱溟");
    for (auto it = range.first; it != range.second; ++it)
    {
        std::cout << it->second << std::endl;
    }

    return 0;
}