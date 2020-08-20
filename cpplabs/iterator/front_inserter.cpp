#include <list>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <cassert>

void test_front_inserter()
{
    int arr[] = {1, 2, 3, 4};
    std::list<int> il;    

    auto inserter = std::front_inserter(il);

    std::copy(std::begin(arr), std::end(arr), inserter);

    // 4 3 2 1
    for (int i : il)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main()
{
    test_front_inserter();

    std::cout << "[TEST front_inserter] PASS" << std::endl;
}