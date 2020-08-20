#include <iterator>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <sstream>

// *operator operator-> 获取当前指向的流的元素
// ++ 推进迭代器

void test_istream_iterator()
{
    std::istringstream iss("1 3 7 6 5");

    auto it = std::find_if(std::istream_iterator<int>(iss), std::istream_iterator<int>(), [](int i) { return i % 2 == 0; } );

    assert(*it == 6);
}

int main()
{
    test_istream_iterator();

    std::cout << "[TEST] istream_iterator PASS" << std::endl;
}