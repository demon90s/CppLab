/*
    #include <chrono>
    std::chrono::stead_clock
    goes at a uniform rate
*/

#include <chrono>
#include <iostream>

int main()
{
    auto start = std::chrono::steady_clock::now();

    std::cout << "Hello\n";

    auto end = std::chrono::steady_clock::now();

    auto dur = end - start;

    if (dur == std::chrono::steady_clock::duration::zero())
    {
        std::cout << "no cost\n";
    }

    std::cout << "duration = " << std::chrono::duration_cast<std::chrono::microseconds>(dur).count() << " micros seconds\n";

    return 0;
}