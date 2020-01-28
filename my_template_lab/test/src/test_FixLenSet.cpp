#include "../library/FixLenSet.hpp"

/*
void test1()
{
    FixLenSet<int, 5> iset;

    iset.Print();

    for (int i = 0; i < 8; i++)
    {
        iset.Insert(i);
    }
    for (int i = 0; i < 8; i++)
    {
        iset.Insert(i);
    }
    iset.Print();

    iset.Erase(3);
    iset.Insert(100);
    iset.Print();

    std::cout << std::boolalpha << iset.HasItem(100) << std::endl;
    std::cout << std::boolalpha << iset.HasItem(101) << std::endl;

    int index = -1;
    auto item = iset.GetItem(100, &index);
    if (item)
    {
        std::cout << *item << " " << index << std::endl;
    }
    item = iset.GetItem(101, &index);
    if (item)
    {
        std::cout << *item << " " << index << std::endl;
    }
}

class Foo
{
public:
    Foo() :
        id(0),
        power(0)
    {}

    Foo(int id_, int power_) :
        id(id_),
        power(power_)
    {}

    static Foo Key(int id_) { return Foo(id_, 0); }

    bool operator==(const Foo &lhs) const
    {
        return id == lhs.id;
    }

    int id;
    int power;
};

std::ostream& operator<<(std::ostream &os, const Foo &foo)
{
    os << foo.id << " " << foo.power;
    return os;
}

void test2()
{
    FixLenSet<Foo, 16> fooset;
    fooset.Insert(Foo(1, 10));
    fooset.Print();

    for (int i = 0; i < 8; i++)
    {
        fooset.Insert(Foo(i, 100 * i));
    }
    for (int i = 0; i < 8; i++)
    {
        fooset.Insert(Foo(i, 100 * i));
    }
    fooset.Print();

    fooset.Erase(0);
    fooset.Insert(Foo(6, 100));
    fooset.Print();

    std::cout << std::boolalpha << fooset.HasItem(6) << std::endl;
    std::cout << std::boolalpha << fooset.HasItem(7) << std::endl;

    int index = -1;
    auto item = fooset.GetItem(6, &index);
    if (item)
    {
        std::cout << *item << " " << index << std::endl;
    }
    item = fooset.GetItem(7, &index);
    if (item)
    {
        std::cout << *item << " " << index << std::endl;
    }
}
*/