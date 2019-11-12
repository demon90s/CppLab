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

// lower_bound(key)
// 返回指向首个不小于(>=) key 的元素的迭代器。若找不到这种元素，则返回尾后迭代器
void test_lower_bound()
{
    std::map<int, std::string, bool(*)(int, int)> is_map([](int lhs, int rhs) { return lhs > rhs; });   // 降序，逻辑反过来了，找首个 <= key 的元素

    is_map.insert( {1, "one"});
    is_map.insert( {10, "ten"});
    is_map.insert( {5, "five"});

    // 10 ten
    // 5 five
    // 1 one

    int i;
    while (std::cin >> i) {
        auto it = is_map.lower_bound(i);
        
        if (it == is_map.end())
        {
            std::cout << "not match\n";
        }
        else
        {
            std::cout << "match: {" << it->first << " " << it->second << "}\n";
        }
    }
}

// lower_bound(key)
// 返回指向首个大于 key 的元素的迭代器。若找不到这种元素，则返回尾后迭代器
void test_upper_bound()
{
    std::map<int, std::string> is_map = {
        {1, "one"},
        {10, "ten"},
        {5, "five"}
    };

    int i;
    while (std::cin >> i) {
        auto it = is_map.upper_bound(i);
        
        if (it == is_map.end())
        {
            std::cout << "not match\n";
        }
        else
        {
            std::cout << "match: {" << it->first << " " << it->second << "}\n";
        }
    }
}

int main()
{
    //test_custom_sort();
    test_lower_bound();
    //test_upper_bound();

    return 0;
}