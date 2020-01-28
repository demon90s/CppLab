#include "../library/FixLenRankList.hpp"

/*
void test1()
{
    FixLenRankList<int, 10> ranklist;

    ranklist.Push(10);
    ranklist.Push(20);
    ranklist.Push(5);
    ranklist.Push(20);

    ranklist.Sort();

    ranklist.PrintRankList();

    std::vector<int> top = ranklist.GetTopList(1);
    std::cout << top[0] << std::endl;

    for (int i = 0; i < 50; i++)
    {
        ranklist.Push(i);
    }
    std::cout << ranklist.GetTop() << std::endl;

    ranklist.Sort();
    ranklist.PrintRankList();
}

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

void test2()
{
    FixLenRankList<Foo, 5> ranklist;

    ranklist.Push(Foo(0, 30));
    ranklist.Push(Foo(1, 10));  // pass
    ranklist.Push(Foo(2, 11));
    ranklist.Push(Foo(3, 22));
    ranklist.Push(Foo(4, 11));
    ranklist.Push(Foo(4, 9));   // pass
    ranklist.Push(Foo(4, 100));

    ranklist.PrintRankList();

    ranklist.Sort();
    std::cout << ranklist.GetTop() << std::endl;
    ranklist.PrintRankList();
}

*/