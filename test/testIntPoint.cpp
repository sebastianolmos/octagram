#include <gtest/gtest.h>
#include"octagram/point.hpp"
#include<string> 
using namespace std;

TEST(IntPoint, ConstructorTest)
{   
    Point<int>* testPoint = new Point<int>();
    EXPECT_TRUE(testPoint->getX() == 0);
    EXPECT_TRUE(testPoint->getY() == 0);
    delete testPoint;
}

TEST(IntPoint, GetXTest)
{   
    int x = 32;
    Point<int>* testPoint = new Point<int>(x, 0);
    EXPECT_TRUE(testPoint->getX() == x);
    delete testPoint;
}

TEST(IntPoint, GetYTest)
{   
    int y = 43;
    Point<int>* testPoint = new Point<int>(0, y);
    EXPECT_TRUE(testPoint->getY() == y);
    delete testPoint;
}

TEST(IntPoint, StringTest)
{   
    int x1 = -60, y1 = 98;
	Point<int> testPoint1(x1, y1);
    stringstream out;
    out << testPoint1;
    EXPECT_TRUE(out.str() == "P(-60, 98)");
}

TEST(IntPoint, EqualTest)
{   
    int x1 = -325, y1 = 1;
	int x2 = -325, y2 = 1;
	Point<int> testPoint1(x1, y1);
	Point<int> testPoint2(x2, y2);
    ASSERT_TRUE(testPoint1 == testPoint2);
}

TEST(IntPoint, NotEqualTest)
{   
    int x1 = -325, y1 = 1;
	int x2 = 325, y2 = 1024;
	Point<int> testPoint1(x1, y1);
	Point<int> testPoint2(x2, y2);
    ASSERT_FALSE(testPoint1 == testPoint2);
}

TEST(IntPoint, CopyTest)
{   
    int x1 = -100, y1 = 69;
	Point<int> testPoint1(x1, y1);
	Point<int> testPoint2 = testPoint1;
    EXPECT_TRUE(testPoint1 == testPoint2);
}

TEST(IntPoint, AddTest)
{   
    int x1 = -8, y1 = 1;
	int x2 = 39, y2 = -2048;
	Point<int> testPoint1(x1, y1);
	Point<int> testPoint2(x2, y2);
    Point<int> testPoint3(31, -2047);
    Point<int> testPoint4 = testPoint1 + testPoint2;
    EXPECT_TRUE(testPoint4 == testPoint3);
}

TEST(IntPoint, SubstTest)
{   
    int x1 = -8, y1 = 1;
	int x2 = 39, y2 = -2048;
	Point<int> testPoint1(x1, y1);
	Point<int> testPoint2(x2, y2);
    Point<int> testPoint3(-47, 2049);
    Point<int> testPoint4 = testPoint1 - testPoint2;
    EXPECT_TRUE(testPoint4 == testPoint3);
}

TEST(IntPoint, ScaleTest)
{   
    int x1 = -8, y1 = 1;
	int scale = 3;
	Point<int> testPoint1(x1, y1);
	Point<int> testPoint2(-24, 3);
    Point<int> testPoint3 = testPoint1 * scale;
    EXPECT_TRUE(testPoint3 == testPoint2);
}