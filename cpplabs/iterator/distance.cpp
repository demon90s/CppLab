#include <iterator>
#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>

// distance(first, last)
// 返回从 first 到 last 的路程
// 如果是随机访问迭代器，那么结果可以是负数（从后往前遍历）

void test_distance()
{
    std::string s = "hello";

    // 字符数
    int cnt = std::distance(s.begin(), s.end());

    assert(cnt == 5);

    // 找到o的位置
    auto o_it = std::find(s.begin(), s.end(), 'o');
    int o_pos = std::distance(s.begin(), o_it);

    assert(o_pos == 4);
}

int main()
{
    test_distance();

    std::cout << "PASS" << std::endl;
}