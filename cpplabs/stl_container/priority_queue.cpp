#include <queue>
#include <iostream>
#include <functional>

/*
    #include <queue>
    priority_queue<>

    排序堆，默认从大到小排序，可以设置一个排序规则。
*/

template<typename T>
void out(T &q)
{
    while (!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << std::endl;
}

void test1()
{
    std::priority_queue<int> q;
    for (int n : {3, 6, 1, 5, 19, 10})
        q.push(n);

    out(q);
}

void test2()
{
    // 修改默认排序规则，改成从小到大
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    for (int n : {3, 6, 1, 5, 19, 10})
        q.push(n);

    out(q);
}

int main()
{
    test1();
    test2();

    return 0;
}