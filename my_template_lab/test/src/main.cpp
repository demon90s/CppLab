#include "gtest/gtest.h"

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);

    // only call once
    // return 0 if all succ
    // otherwise, not
    return RUN_ALL_TESTS();
}
