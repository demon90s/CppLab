/*
    std::equal
    两个范围相等，返回 true ，否则返回 false

    equal(first1, last1, first2)
    使用 operator== 比较元素

    equal(first1, last1, first2, binary_pred)
    使用二元谓词比较
*/

#include <algorithm>
#include <vector>
#include <iostream>
#include <list>
#include <cassert>

int main(int argc, char const *argv[])
{
    std::vector<int> vec {1, 2, 3, 4, 5};
    std::list<int> lst {1, 2, 3, 4, 5, 6};

    bool is_equal = std::equal(vec.begin(), vec.end(), lst.begin());
    assert(is_equal == true);   // 尽管长度不一样，但比较的范围一样，内容也一样

    int arr[] = {1, 2, 3, 4, 5};
    is_equal = std::equal(std::begin(arr), std::end(arr), vec.begin());
    assert(is_equal == true);

    vec[2] = 10;
    is_equal = std::equal(std::begin(arr), std::end(arr), vec.begin());
    assert(is_equal == false);

    std::cout << "[TEST] std::equal PASS\n";

    return 0;
}
