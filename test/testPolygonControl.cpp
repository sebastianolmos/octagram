#include <gtest/gtest.h>
#include"octagram/polygon.hpp"
#include"octagram/point.hpp"

TEST(sPolygon, SimpleTest)
{   
    int t = 1;
    Polygon p1;

    Point<int> p0(1, 2);
	p1.addPoint(p0);

    EXPECT_EQ(t, p1.getSize());
}