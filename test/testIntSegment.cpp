#include <gtest/gtest.h>
#include"octagram/segment.hpp"

TEST(IntSegment, SimpleTest)
{   
    int t = 1;
    Segment<int> s1(1, 2, 3, 4);
    EXPECT_EQ(t, 1);
}