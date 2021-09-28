#include <gtest/gtest.h>
#include"octagram/polygon.hpp"

TEST(DummyPolygon, TestSimple)
{   
    int t = 1;
    polygon p1(t);
    EXPECT_EQ(1, t);
}