#include "../library/FixLenHashTable.hpp"
#include <string>
#include <iostream>

void test1()
{
    FixLenHashTable<int, std::string, 10> id_name_map;

    std::cout << id_name_map.Put(1, "liudiwen") << std::endl;       // 1
    std::cout << id_name_map.Put(1, "liudiwen") << std::endl;       // 0

    std::cout << *id_name_map.Get(1) << std::endl; // liudiwen

    auto name = id_name_map.Get(2);
    if (!name)
    {
        std::cout << "id 2 not found" << std::endl; // not found
    }
}

// 为这个类型定义 hash 特例化
class Foo {
public:
    std::string str;
    int a;
    double d;
};

bool operator==(const Foo &lhs, const Foo &rhs)
{
    return lhs.str == rhs.str &&
        lhs.a == rhs.a &&
        lhs.d == rhs.d;
}

// 打开命名空间 std ，以便特例化 std::hash
namespace std {
template<>
struct hash<Foo>
{
    typedef size_t result_type;
    typedef Foo argument_type;
    size_t operator()(const Foo& foo) const
    {
        return hash<string>()(foo.str) ^
            hash<int>()(foo.a) ^
            hash<double>()(foo.d);
    }
};
}

void test2()
{
    FixLenHashTable<Foo, std::string, 10> foo_str_map;

    Foo key {"diwen", 29, 888.888};
    std::cout << foo_str_map.Put(key, "diwen") << std::endl;
    std::cout << foo_str_map.Put(key, "diwen") << std::endl;

    std::cout << *foo_str_map.Get(key) << std::endl;

    key.a = 30;
    auto name = foo_str_map.Get(key);
    if (!name)
    {
        std::cout << "not found" << std::endl; // not found
    }
}

void test3()
{
    FixLenHashTable<int, std::string, 5> id_string_map;

    id_string_map.Put(1, "diwen");
    id_string_map.Put(2, "miemie");
    id_string_map.Put(3, "meili");

    id_string_map.Travel([](int id, std::string &name) { 
        if (id > 0)
        {
            std::cout << name << std::endl;
        }
    });

    std::cout << "------------------------\n";
    id_string_map.Erase(1);
    id_string_map.Travel([](int id, std::string &name) { 
        if (id > 0)
        {
            std::cout << name << std::endl;
        }
    });
}

int main()
{
    //test1();
    //test2();
    test3();
}