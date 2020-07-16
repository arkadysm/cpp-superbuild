#include <gtest/gtest.h>

TEST(simple_tests, test_success1)
{
    EXPECT_TRUE(true);
}

TEST(simple_tests, test_success2)
{
    EXPECT_TRUE(true);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
