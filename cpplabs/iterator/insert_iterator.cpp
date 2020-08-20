#include <iterator>
#include <set>
#include <iostream>
#include <algorithm>
#include <cassert>

void test_insert_iterator()
{
    int arr[] = {1, 1, 2, 2, 3, 3};
    std::set<int> iset;

    auto inserter = std::insert_iterator<decltype(iset)>(iset, iset.begin());

    std::copy(std::begin(arr), std::end(arr), inserter);

    // 1 2 3
    for (int i : iset)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main()
{
    test_insert_iterator();

    std::cout << "[TEST insert_iterator] PASS" << std::endl;
}