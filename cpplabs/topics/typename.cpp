/*
    模板中为什么会使用 typename 标记一个子类型？

    因为如同这样的语法有二义性：
    T::value_type

    value_type 如果是一个static变量，是合法的，如果是一个类型, 也是合法的。
*/

#include <iostream>
#include <vector>

template<typename T>
void Foo(typename T::iterator begin, typename T::iterator end)
{
    for (typename T::iterator it = begin; it != end; ++it)
    {
        std::cout << *it << std::endl;
    }
}

int main()
{
    std::vector<int> ivec {1, 2, 3, 4};

    Foo<std::vector<int>>(ivec.begin(), ivec.end());
}