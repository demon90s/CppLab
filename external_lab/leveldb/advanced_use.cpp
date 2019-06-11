#include <iostream>
#include <cassert>
#include <leveldb/db.h>

// Slice 是key和value的类型，它只保有指针，生存期依赖外部
// 从而避免了copy of string
void Slice_test()
{
    leveldb::Slice s1 = "Hello";
    std::cout << s1.ToString() << std::endl;
}

int main()
{
    Slice_test();

    return 0;
}
