#include "FixLenHashTable.hpp"
#include "gtest/gtest.h"

TEST(test_FixLenHashTable, test_Put_Get)
{
    FixLenHashTable<int, std::string, 10> id_name_map;

    EXPECT_TRUE(id_name_map.Put(1, "liudiwen"));
    EXPECT_FALSE(id_name_map.Put(1, "liudiwen"));

    EXPECT_STREQ((*id_name_map.Get(1)).c_str(), "liudiwen");
    EXPECT_EQ(id_name_map.Get(2), nullptr);
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

TEST(test_FixLenHashTable, test_Custom_key)
{
    FixLenHashTable<Foo, std::string, 10> foo_str_map;

    Foo key {"diwen", 29, 888.888};

    EXPECT_TRUE(foo_str_map.Put(key, "diwen"));
    EXPECT_FALSE(foo_str_map.Put(key, "diwen"));

    EXPECT_STREQ((*foo_str_map.Get(key)).c_str(), "diwen");

    key.a = 30;
    auto name = foo_str_map.Get(key);
    EXPECT_EQ(name, nullptr);
}

TEST(test_FixLenHashTable, test_Erase)
{
    FixLenHashTable<int, std::string, 4> id_string_map;

    id_string_map.Put(1, "diwen");
    id_string_map.Put(2, "miemie");
    id_string_map.Put(3, "meili");
    id_string_map.Put(11, "xxx");

    id_string_map.Erase(11);

    auto value = id_string_map.Get(11);
    EXPECT_EQ(value, nullptr);
}

TEST(test_FixLenHashTable, test_big_data)
{
    FixLenHashTable<int, std::string, 10000> id_string_map;

    for (int i = 0; i < 5000; i++)
    {
        bool ret = id_string_map.Put(i, std::to_string(i));

        EXPECT_TRUE(ret);
    }

    for (int i = 10000; i < 15000; i++)
    {
        bool ret = id_string_map.Put(i, std::to_string(i));

        EXPECT_TRUE(ret);
    }

    for (int i = 15000; i < 20000; i++)
    {
        bool ret = id_string_map.Put(i, std::to_string(i));

        EXPECT_FALSE(ret);
    }

    for (int i = 0; i < 5000; i++)
    {
        auto v = id_string_map.Get(i);

        EXPECT_STREQ(v->c_str(), std::to_string(i).c_str());
    }

    for (int i = 10000; i < 15000; i++)
    {
        auto v = id_string_map.Get(i);

        EXPECT_STREQ(v->c_str(), std::to_string(i).c_str());
    }

    for (int i = 0; i < 10000; i++)
    {
        id_string_map.Erase(i);
    }
    EXPECT_EQ(5000, id_string_map.Size());
}
