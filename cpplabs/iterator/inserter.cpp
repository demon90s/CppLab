#include <iterator>
#include <set>
#include <iostream>
#include <algorithm>
#include <cassert>

void test_inserter()
{
    int arr[] = {1, 1, 2, 2, 3, 3};
    std::set<int> iset;

    auto inserter = std::inserter(iset, iset.begin());

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
    test_inserter();

    std::cout << "[TEST inserter] PASS" << std::endl;
}