#include <iterator>
#include <vector>
#include <iostream>
#include <cassert>

// it next(it, n)
// 往后移动n，返回移动后的迭代器, n默认为1

// it prev(it, n)
// 往前回去n，返回移动后的迭代器，n默认为1

void test_next()
{
    std::vector<int> ivec = {1, 2, 3, 4};

    auto it = ivec.begin();
    auto it2 = std::next(it, 2);

    assert(*it2 == 3);
    assert(*it == 1);

    auto it3 = std::next(it2, -2);
    
    assert(*it3 == 1);
    assert(*it2 == 3);
}

void test_prev()
{
    std::vector<int> ivec = {1, 2, 3, 4};

    auto it = ivec.end();
    auto it2 = std::prev(it, 1);
    auto it3 = std::prev(it2, 3);

    assert(*it2 == 4);
    assert(*it3 == 1);
}

int main()
{
    test_next();
    test_prev();

    std::cout << "[TEST next prev] PASS" << std::endl;
}