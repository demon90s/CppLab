#include "FixLenRankList.hpp"
#include "gtest/gtest.h"

TEST(test_FixLenRankList, test1)
{
    FixLenRankList<int, 10> ranklist;

    ranklist.Push(10);
    ranklist.Push(20);
    ranklist.Push(5);
    ranklist.Push(20);

    ranklist.PrintRankList();

    std::vector<int> top = ranklist.GetTopList(1);
    EXPECT_EQ(20, top[0]);

    for (int i = 0; i < 50; i++)
    {
        ranklist.Push(i);
    }
    EXPECT_EQ(49, ranklist.GetTop());
}

namespace fixlenranklist
{
class Foo
{
public:
    Foo() :
        id(0),
        value(0)
    {
    }
    Foo(int _id, int _value) : 
        id(_id),
        value(_value)
    {
    }
    bool operator==(const Foo &rhs) const
    {
        return id == rhs.id;
    }

    bool operator<(const Foo &rhs) const
    {
        return value < rhs.value;
    }
    int id;
    int value;
};

std::ostream& operator<<(std::ostream &os, const Foo &foo)
{
    os << foo.id << " " << foo.value;
    return os;
}

}

void test2()
{
    FixLenRankList<fixlenranklist::Foo, 5> ranklist;

    ranklist.Push(fixlenranklist::Foo(0, 30));
    ranklist.Push(fixlenranklist::Foo(1, 10));  // pass
    ranklist.Push(fixlenranklist::Foo(2, 11));
    ranklist.Push(fixlenranklist::Foo(3, 22));
    ranklist.Push(fixlenranklist::Foo(4, 11));
    ranklist.Push(fixlenranklist::Foo(4, 9));   // pass
    ranklist.Push(fixlenranklist::Foo(4, 100));

    const auto &top = ranklist.GetTop();
    EXPECT_EQ(top.id, 4);
}
