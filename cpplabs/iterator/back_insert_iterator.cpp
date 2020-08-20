#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>

// back_insert_iterator 只有赋值操作，其他操作无意义，赋值即向其绑定的容器 push_back 一个元素

void test_back_insert_iterator()
{
    std::vector<int> iv;

    int i = 0;
    std::generate_n(std::back_insert_iterator<decltype(iv)>(iv), 3, [i]() mutable { return i++; });

    assert(iv[0] == 0);
    assert(iv[1] == 1);
    assert(iv[2] == 2);
    
    auto insert_it = std::back_insert_iterator<decltype(iv)>(iv);
    *insert_it = 100;
    assert(iv[3] == 100);
}

int main()
{
    test_back_insert_iterator();

    std::cout << "[TEST back_insert_iterator] PASS" << std::endl;
}