#include <iostream>
#include <gtest/gtest.h>

TEST(test, hello) {
    std::cout << "Hello google test\n";
}

TEST(test, ASSERT) {
    ASSERT_TRUE(100 < 90) << "Assert failed!!!!!";  // 失败才会输出
    // assert 失败，终止function执行
}

TEST(test, EXPECT) {
    EXPECT_TRUE(100 < 90) << "Expect failed!!!!!";
    // expect 失败，仍会继续function执行
    
    std::cout << "Expect test done.\n";
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);

    // only call once
    // return 0 if all succ
    // otherwise, not
    return RUN_ALL_TESTS();
}
