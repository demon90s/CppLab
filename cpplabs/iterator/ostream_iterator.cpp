#include <iterator>
#include <algorithm>
#include <iostream>
#include <cassert>

// 对迭代器的赋值操作相当于对第一个参数执行 << ，并在后面追加分隔符
// 其他操作没意义

void test_ostream_iterator()
{
    int arr[] = {1, 2, 3, 4};

    // 1|2|3|4|
    std::copy(std::begin(arr), std::end(arr), std::ostream_iterator<int>(std::cout, "|"));
    std::cout << std::endl;
}

int main()
{
    test_ostream_iterator();

    std::cout << "[TEST ostream_iterator] PASS" << std::endl;
}