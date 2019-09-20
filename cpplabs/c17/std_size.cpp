// std::size
/*
#include <iterator>
// 返回容器的大小
template<class C>
constexpr auto size(const C& c) -> decltype(c.size());

// 返回array的大小
template<class T, std::size_t N>
constexpr std::size_t size(const T (&array)[N]) noexcept;
*/

#include <iterator>
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> ivec = {1, 2, 3, 4};
    std::cout << std::size(ivec) << std::endl;      // 4

    int arr[] = {1, 2, 3};
    std::cout << std::size(arr) << std::endl;       // 3

    return 0;
}
