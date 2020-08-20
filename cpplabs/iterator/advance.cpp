#include <cassert>
#include <iostream>
#include <iterator>
#include <vector>

// advance(it, n)
// 向前前进N，如果是双向的，那么N可以是负数

void test_advance()
{
    std::vector<int> iv = {1, 2, 3};

    auto it = iv.begin();
    std::advance(it, 2);

    assert(*it == 3); 

    std::advance(it, -1);

    assert(*it == 2);
}

int main()
{
    test_advance();

    std::cout << "PASS" << std::endl;
}