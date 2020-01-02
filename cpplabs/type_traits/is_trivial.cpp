#include <iostream>
#include <type_traits>

/*
    检查一个类型是否是平凡类型
*/

struct A
{
    int m;
};

class B
{
    int *m;
};

struct C
{
    C() {}
};

struct D
{
    D() = default;

    int a;
};

int main()
{
    std::cout << std::boolalpha;

    std::cout << std::is_trivial<A>::value << std::endl;    // true
    static_assert(std::is_trivial<A>::value, "A must be a trivial class");  // 编译时即可检查

    std::cout << std::is_trivial<B>::value << std::endl;    // true

    std::cout << std::is_trivial<C>::value << std::endl;    // false

    std::cout << std::is_trivial<D>::value << std::endl;    // true
}