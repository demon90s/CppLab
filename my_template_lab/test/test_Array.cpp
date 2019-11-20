#include "../library/Array.hpp"
#include <iostream>
#include <algorithm>

int main()
{
    Array<int, 5> iarray {1, 2, 3, 4, 5};

    for (int i = 0; i < iarray.Size(); i++)
    {
        std::cout << iarray[i] << std::endl;
    }

    for (int i : iarray)
    {
        std::cout << i << std::endl;
    }

    int raw[5];
    iarray.Copy(raw);
    for (int i = 0; i < 5; i++)
    {
        std::cout << raw[i] << std::endl;
    }

    std::cout << "sorting...\n";
    std::sort(iarray.begin(), iarray.end(), [](int lhs, int rhs) { return lhs > rhs; });
    for (int i : iarray)
    {
        std::cout << i << std::endl;
    }
}
