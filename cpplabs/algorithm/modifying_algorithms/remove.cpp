#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

// std::remove(beg, end, v) 
// 将序列中等于v的元素删除，返回最后一个没删掉的元素的后一个迭代器。如果没有，返回end
// 注意，元素的数量不会改变

int main()
{
    std::vector<int> vec {1, 2, 3, 4, 5};

    auto it = std::remove(vec.begin(), vec.end(), 6);
    assert(it == vec.end());

    it = std::remove(vec.begin(), vec.end(), 2);
    assert(std::distance(vec.begin(), it) == 4);

    // 真正删除的方法
    vec = {1, 2, 3, 4, 2, 5};
    vec.erase(std::remove(vec.begin(), vec.end(), 2), vec.end());
    assert(vec.size() == 4);
    assert(std::find(vec.begin(), vec.end(), 2) == vec.end());
}