#include "../library/Array.hpp"
#include <iostream>
#include <algorithm>

void test1()
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

void test2()
{
    Array<int, 5> iarray {8, 4, 1, 5, 2};

    std::cout << iarray.MaxElement() << std::endl;
    std::cout << iarray.MinElement() << std::endl;

    auto item = iarray.GetElement(5);
    if (item)
    {
        std::cout << *item << std::endl;
    }

    std::cout << "---------------------sort\n";
    auto sort_res = iarray.Sort();
    for (int *i : sort_res)
    {
        std::cout << *i << std::endl;
    }
    std::cout << "---------------------sort end\n";
}

struct Foo
{
    bool operator<(const Foo &rhs) const
    {
        return power < rhs.power;
    }

    int id;
    int power;
};

std::ostream &operator<<(std::ostream &os, const Foo &foo)
{
    os << foo.id << " " << foo.power;
    return os;
}

void test3()
{
    Array<Foo, 5> foo_array;
    foo_array[0] = {1, 2};
    foo_array[1] = {2, 200};
    foo_array[2] = {3, 99};
    foo_array[3] = {4, 12};
    foo_array[4] = {5, 20};

    std::cout << foo_array.MaxElement([](const Foo &lhs, const Foo &rhs) { return lhs.power < rhs.power; }) << std::endl;
    std::cout << foo_array.MinElement([](const Foo &lhs, const Foo &rhs) { return lhs.power < rhs.power; }) << std::endl;

    auto item = foo_array.GetElement([](const Foo &item) { return item.id == 5; });
    if (item)
    {
        std::cout << *item << std::endl;
    }

    std::cout << "sorting....\n";
    auto sort_res = foo_array.Sort([](const Foo &lhs, const Foo &rhs) { return lhs.power > rhs.power; });
    for (const auto &item : sort_res)
    {
        std::cout << *item << "\n";
    }
    std::cout << "sorting....end\n";

    std::cout << "sorting....\n";
    sort_res = foo_array.Sort();
    for (const auto &item : sort_res)
    {
        std::cout << *item << "\n";
    }
    std::cout << "sorting....end\n";
}

int main()
{
    test3();
    //test2();
}
