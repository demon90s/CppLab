#include <tuple>
#include <iostream>
#include <cassert>
#include <cstring>

int main()
{
    auto t = std::make_tuple(1, 3.14, "hello");

    assert(std::get<0>(t) == 1);
    assert(std::get<1>(t) == 3.14);
    assert(strcmp(std::get<2>(t), "hello") == 0);

    std::cout << "[TEST] tuple PASS\n";
}
