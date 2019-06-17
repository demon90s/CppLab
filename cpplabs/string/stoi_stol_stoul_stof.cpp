/*
    stoi(s, p, b) - 返回类型 int
    stol(s, p, b) - 返回类型 long
    stoul(s, p, b) - 返回类型 unsigned long
    stof(s, p) - 返回类型 float

    返回s的起始子串（表示整数内容）的数值。
    p 是 size_t 类型的指针，保存s中地一个非数值字符的下标，默认为0 。
    b 表示转换基数，默认是10。 

    不能转换则会抛出异常：std::invalid_argument
    如果超出范围，则抛出 std::out_of_range
*/

#include <string>
#include <iostream>
#include <google/gtest/gtest.h>

TEST(cpplab, stoi_example)
{
    int i = std::stoi("42");
    ASSERT_TRUE(i == 42);

    i = std::stoi("1010", 0, 2);
    ASSERT_TRUE(i == 10);
}

TEST(cpplab, stoi_exception)
{
    {
        bool catched_invalid_argument = false;
        try {
            int i = std::stoi("bbb");
            (void)i;
        }
        catch (std::invalid_argument e) {
            catched_invalid_argument = true;
        }
        ASSERT_TRUE(catched_invalid_argument);
    }

    {
        bool catched_out_of_range = false;
        try {
            int i = std::stoi("12345678900");
            (void)i;
        }
        catch (std::out_of_range e) {
            catched_out_of_range = true;
        }
        ASSERT_TRUE(catched_out_of_range);
    }
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
