#include <map>
#include <iostream>
#include <string>

void test_custom_sort()
{
    // 从大到小排key
    std::map<int, std::string, bool(*)(int, int)> num_map(
        [](int a, int b) { return a > b; }
        );
    
    num_map[1] = "one";
    num_map[2] = "two";
    num_map[3] = "three";

    for (const auto &p : num_map)
    {
        std::cout << p.first << ": " << p.second << std::endl;
    }
}

int main()
{
    test_custom_sort();

    return 0;
}