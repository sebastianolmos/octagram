#include <gtest/gtest.h>
#include"octagram/point.hpp"

TEST(DummyPoint, TestSimple2)
{   
    int t = 1;
    Point<int> p1(1, 2);
    EXPECT_EQ(t, p1.getX());
}