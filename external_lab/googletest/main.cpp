#include <iostream>
#include <gtest/gtest.h>

TEST(test, hello) {
    std::cout << "Hello google test\n";
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
