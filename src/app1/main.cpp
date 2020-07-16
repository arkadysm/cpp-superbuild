#include <gtest/gtest.h>

TEST(simple_tests, test_success)
{
    EXPECT_TRUE(true);
}

TEST(simple_tests, test_failure)
{
    EXPECT_TRUE(false);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
