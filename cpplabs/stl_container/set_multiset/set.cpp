#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
#include <chrono>

using namespace std;

void test1()
{
    // type of the collection:
    // - no duplicates
    // -elements are integral values
    // -descending order
    set<int, greater<int>> coll1;

    // insert elements in random order using different member functions
    coll1.insert({4, 3, 5, 1, 6, 2});
    coll1.insert(5);

    // print all elements
    for (int elem : coll1) {
        cout << elem << ' ';
    }
    cout << endl;

    // insert 4 again and process return value
    auto status = coll1.insert(4);
    if (status.second) {
        cout << "4 inserted as element "
             << distance(coll1.begin(), status.first) + 1 << endl;
    }
    else {
        cout << "4 already exists" << endl;
    }

    // assign elements to another set with ascending order
    set<int> coll2(coll1.cbegin(), coll1.cend());

    // print all elements of the copy using stream iterators
    copy(coll2.cbegin(), coll2.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // remove all elements up to element with value 3
    coll2.erase(coll2.begin(), coll2.find(3));

    // remove all elements with value 5
    int num;
    num = coll2.erase(5);
    cout << num << " element(s) removed" << endl;

    // print all elements
    copy(coll2.cbegin(), coll2.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

// 删除尾部元素，由于 std::set 的迭代器满足双向迭代器，因此可以直接删尾巴
void test2()
{
    std::set<int> iset {1, 2, 3, 4, 5};

    // 前提保证至少有一个元素
    iset.erase(--iset.end());

    for (int i : iset)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    // output: 1 2 3 4 5
}

// 测试stl性能，-O2选项会缩短4倍左右的执行时间
void benchmark()
{
    auto start = std::chrono::steady_clock::now();

    //---
    // insert 100 million strings
    std::set<std::string> strset;
    for (int i = 0; i < 1000000; i++)
    {
        strset.insert("hello");
    }
    //---

    auto dur = std::chrono::steady_clock::now() - start;

    std::cout << "benchmark done, cost: " << std::chrono::duration_cast<std::chrono::microseconds>(dur).count() / 1000.0 << " ms\n";
}

int main()
{
    //test2();
    benchmark();
}
