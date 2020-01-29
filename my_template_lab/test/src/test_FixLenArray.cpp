#include "FixLenArray.hpp"
#include "gtest/gtest.h"

#include <iostream>
#include <algorithm>

TEST(test_FixLenArray, test1)
{
    FixLenArray<int, 5> iarray {1, 2, 3, 4, 5};

    for (int i = 0; i < iarray.Size(); i++)
    {
        EXPECT_EQ(i + 1, iarray[i]);
    }

    int v = 1;
    for (int i : iarray)
    {
        EXPECT_EQ(i, v);
        v++;
    }

    int raw[5];
    iarray.Copy(raw);
    for (int i = 0; i < 5; i++)
    {
        EXPECT_EQ(i + 1, raw[i]);
    }

    std::sort(iarray.begin(), iarray.end(), [](int lhs, int rhs) { return lhs > rhs; });
    
    v = 5;
    for (auto i : iarray)
    {
        EXPECT_EQ(v, i);
        v--;
    }
}

TEST(test_FixLenArray, test2)
{
    FixLenArray<int, 5> iarray {8, 4, 1, 5, 2};

    EXPECT_EQ(8, iarray.MaxElement());
    EXPECT_EQ(1, iarray.MinElement());

    auto item = iarray.GetElement(5);
    EXPECT_EQ(*item, 5);

    auto sort_res = iarray.Sort();
    EXPECT_EQ(1, *sort_res[0]);
    EXPECT_EQ(2, *sort_res[1]);
    EXPECT_EQ(4, *sort_res[2]);
    EXPECT_EQ(5, *sort_res[3]);
    EXPECT_EQ(8, *sort_res[4]);
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

TEST(test_FixLenArray, test3)
{
    FixLenArray<Foo, 5> foo_array;
    foo_array[0] = {1, 2};
    foo_array[1] = {2, 200};
    foo_array[2] = {3, 99};
    foo_array[3] = {4, 12};
    foo_array[4] = {5, 20};

    auto &max_elem = foo_array.MaxElement([](const Foo &lhs, const Foo &rhs) { return lhs.power < rhs.power; });
    auto &min_elem = foo_array.MinElement([](const Foo &lhs, const Foo &rhs) { return lhs.power < rhs.power; });

    EXPECT_EQ(max_elem.id, 2);
    EXPECT_EQ(min_elem.id, 1);

    auto item = foo_array.GetElement([](const Foo &item) { return item.id == 5; });
    EXPECT_EQ(item->power, 20);
}