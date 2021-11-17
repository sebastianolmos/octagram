#include <gtest/gtest.h>
#include "octagram/algorithm/convexhull.hpp"

TEST(algTest, iniTest)
{   
    int t = testsum(1,2);
    EXPECT_TRUE(t == 3);

    float tt = testsum2<float>(2.0, 4.0);
    EXPECT_TRUE(tt > 5.0);
}