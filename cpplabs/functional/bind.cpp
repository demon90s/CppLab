#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

void print(int i, char delim)
{
    std::cout << i << delim;
}

int main()
{
    std::vector<int> iv;

    std::cout << "Input some integers: ";
    int i;
    while (std::cin >> i) {
        iv.push_back(i);
    }

    auto filter = std::bind(print, std::placeholders::_1, ' ');

    std::for_each(iv.begin(), iv.end(), filter);
    std::cout << std::endl;
}
