#include <gtest/gtest.h>
#include"octagram/point.hpp"

TEST(DummyPoint, TestSimple2)
{   
    int t = 1;
    point p1(t);
    EXPECT_EQ(p1.getX(), t);
}