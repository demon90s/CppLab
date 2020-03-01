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
#include <cassert>

void test1()
{
    int i = std::stoi("42");
    assert(i == 42);

    i = std::stoi("1010", 0, 2);
    assert(i == 10);
}

void test2()
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
        assert(catched_invalid_argument);
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
        assert(catched_out_of_range);
    }
}

int main(int argc, char* argv[])
{
    test1();
    test2();

    std::cout << "[TEST] stoi, stol, stoul, stof PASS\n";
}
