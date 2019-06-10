#include <functional>
#include <iostream>
#include <list>

// #include <functional>
// greator<T>
// operator(n1, n2); 检查n1是否大于n2

void test1()
{
    std::greater<int> g;

    std::cout << std::boolalpha;
    std::cout << g(10, 5) << std::endl;     // true
    std::cout << g(0, 2) << std::endl;      // false
}

void test2()
{
    std::list<int> l{10, 8, 12, 77, 1};
    l.sort(std::greater<int>());    // 从大到小排序

    for (int n : l)
        std::cout << n << " ";
    std::cout << std::endl;
}

int main()
{
    //test1();
    test2();
    return 0;
}