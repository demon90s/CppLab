#include <iostream>
#include <unordered_map>
#include <string>
#include <cassert>

void test_usage()
{
    std::unordered_map<std::string, std::string> color_map = 
    {
        { "RED", "#FF0000" },
        { "GREEN", "#00FF00" },
        { "BLUE", "#0000FF" },
    };
    sizeof(color_map);

    // Iterate and Print
    for (const auto &elem : color_map)
    {
        std::cout << "{" << elem.first << ": " << elem.second << "}\n";
    }
    std::cout << std::endl;

    // Insert
    color_map["BLACK"] = "#000000";
    color_map["WHITE"] = "#FFFFFF";

    // Get(or insert if not exist)
    std::cout << "BLACK HEX CODE: " << color_map["BLACK"] << std::endl;
}

void test_swap()
{
    std::unordered_map<int, std::string> is_map1 = 
    {
        {1, "One"},
        {2, "Two"}
    };
    std::unordered_map<int, std::string> is_map2 = 
    {
        {1, "Yi"},
        {2, "Er"},
    };

    auto it1 = is_map1.find(1);
    auto it2 = is_map2.find(1);

    is_map1.swap(is_map2);

    //std::cout << it1->first << ": " << it1->second << std::endl;
    //std::cout << it2->first << ": " << it2->second << std::endl;

    // swap 后，迭代器仍有效
    // 但需要注意，旧的指向 end 的迭代器会失效
    assert(it1->second == "One");
    assert(it2->second == "Yi");
}

int main()
{
    test_usage();
    test_swap();

    std::cout << "PASS" << std::endl;
}