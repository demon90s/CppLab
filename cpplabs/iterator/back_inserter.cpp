#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>

// 创建一个绑定到容器的 back_inserter
// 它只有赋值操作有意义, 赋值即向其绑定的容器 push_back 一个元素

void test_back_inserter()
{
    std::vector<int> iv;

    int i = 0;
    std::generate_n(std::back_inserter(iv), 3, [i]() mutable { return i++; });

    assert(iv[0] == 0);
    assert(iv[1] == 1);
    assert(iv[2] == 2);
    
    auto insert_it = std::back_inserter(iv);
    *insert_it = 100;
    assert(iv[3] == 100);
}

int main()
{
    test_back_inserter();

    std::cout << "[TEST back_inserter] PASS" << std::endl;
}