/*
    #include =<utility>

    pair 会执行值初始化。
*/

#include <utility>
#include <iostream>

int main()
{
    std::pair<int, int> p;
    // p.first == 0, p.second == 0
    std::cout << p.first << " " << p.second << std::endl;

    p.first = 10;
    p.second = 100;

    std::cout << p.first << " " << p.second << std::endl;
}