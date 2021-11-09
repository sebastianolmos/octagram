#include <gtest/gtest.h>
#include"octagram/segment.hpp"
#include"octagram/point.hpp"
#include<string> 
using namespace std;

TEST(IntSegment, ConstructorTest)
{   
    Segment<int>* testSeg = new Segment<int>();
    Point<int> zeroPoint(0, 0);
    ASSERT_TRUE(zeroPoint == testSeg->getOrigin());
    ASSERT_TRUE(zeroPoint == testSeg->getEnd());
    delete testSeg;

    int x1 = -65, y1 = 43;
	int x2 = 16, y2 = -9;
    Point<int> testPoint1(x1, y1);
	Point<int> testPoint2(x2, y2);
    Segment<int>* testSeg1 = new Segment<int>(x1, y1, x2, y2);
    ASSERT_TRUE(testPoint1 == testSeg1->getOrigin());
    ASSERT_TRUE(testPoint2 == testSeg1->getEnd());
    delete testSeg1;
}

TEST(IntSegment, EqualTest)
{   
    Point<int> testPoint1(0, -4);
	Point<int> testPoint2(10, 25);
    Point<int> testPoint3(0, -4);
	Segment<int> testSeg1(testPoint1, testPoint2);
	Segment<int> testSeg2(testPoint3, testPoint2);
    ASSERT_TRUE(testSeg1 == testSeg2);
}

TEST(IntSegment, NotEqualTest)
{   
    Point<int> testPoint1(0, -4);
	Point<int> testPoint2(10, 25);
    Point<int> testPoint3(-2, -4);
	Segment<int> testSeg1(testPoint1, testPoint2);
	Segment<int> testSeg2(testPoint3, testPoint2);
    ASSERT_FALSE(testSeg1 == testSeg2);
}

TEST(IntSegment, PointsConstructorTest)
{   
    int x1 = 5, y1 = 3;
	int x2 = 3, y2 = 8;
    Point<int> testPoint1(x1, y1);
	Point<int> testPoint2(x2, y2);
    Segment<int> resultSeg(testPoint1, testPoint2);
	Segment<int> expectedSeg(x1, y1, x2, y2);
    EXPECT_TRUE(resultSeg == expectedSeg);
}

TEST(IntSegment, getOriginTest)
{   
    Point<int> testPoint(10, 20);
    Point<int> zeroPoint(0, 0);
    Segment<int>* testSeg = new Segment<int>(testPoint, zeroPoint);
    EXPECT_TRUE(testPoint == testSeg->getOrigin());
    EXPECT_TRUE(zeroPoint == testSeg->getEnd());
    delete testSeg;
}

TEST(IntSegment, getEndTest)
{   
    Point<int> testPoint(10, 20);
    Point<int> zeroPoint(0, 0);
    Segment<int>* testSeg = new Segment<int>(zeroPoint, testPoint);
    EXPECT_TRUE(zeroPoint == testSeg->getOrigin());
    EXPECT_TRUE(testPoint == testSeg->getEnd());
    delete testSeg;
}

TEST(IntSegment, setOriginTest)
{   
    Point<int> testPoint(10, 20);
    Point<int> zeroPoint(0, 0);
    Segment<int>* testSeg = new Segment<int>();
    EXPECT_TRUE(zeroPoint == testSeg->getOrigin());
    EXPECT_TRUE(zeroPoint == testSeg->getEnd());

    testSeg->setOrigin(testPoint);
    EXPECT_TRUE(testPoint == testSeg->getOrigin());
    EXPECT_TRUE(zeroPoint == testSeg->getEnd());
    delete testSeg;
}

TEST(IntSegment, setEndTest)
{   
    Point<int> testPoint(10, 20);
    Point<int> zeroPoint(0, 0);
    Segment<int>* testSeg = new Segment<int>();
    EXPECT_TRUE(zeroPoint == testSeg->getOrigin());
    EXPECT_TRUE(zeroPoint == testSeg->getEnd());

    testSeg->setEnd(testPoint);
    EXPECT_TRUE(zeroPoint == testSeg->getOrigin());
    EXPECT_TRUE(testPoint == testSeg->getEnd());
    delete testSeg;
}

TEST(IntSegment, StringTest)
{   
    int x1 = -60, y1 = 98, x2 = 3, y2 = 100;
	Segment<int> testSeg1(x1, y1, x2, y2);
    stringstream out;
    out << testSeg1;
    EXPECT_TRUE(out.str() == "S(From P(-60, 98) to P(3, 100))");
}

TEST(IntSegment, getLength2Test)
{   
    int x1 = 2, y1 = 1, x2 = 5, y2 = 5;
	Segment<int> testSeg1(x1, y1, x2, y2);
    EXPECT_TRUE(testSeg1.getLength2() == 25);
}

TEST(IntSegment, getLengthTest)
{   
    int x1 = 0, y1 = 1, x2 = 6, y2 = 5;
	Segment<int> testSeg1(x1, y1, x2, y2);
    float result = sqrt(52);
    EXPECT_TRUE(fabs(testSeg1.getLength() - result) < 1E-6);
}

TEST(IntSegment, leftTest)
{   
    int x1 = -1, y1 = -1, x2 = 5, y2 = 3;
	Segment<int> testSeg1(x1, y1, x2, y2);
    Point<int> testPoint(0, 0);
    EXPECT_TRUE(testSeg1.left(testPoint));
    EXPECT_FALSE(testSeg1.right(testPoint));
}

TEST(IntSegment, rigthTest)
{   
    int x1 = -1, y1 = -1, x2 = 5, y2 = 6;
	Segment<int> testSeg1(x1, y1, x2, y2);
    Point<int> testPoint(4, 0);
    EXPECT_TRUE(testSeg1.right(testPoint));
    EXPECT_FALSE(testSeg1.left(testPoint));
}

TEST(IntSegment, colinearTest)
{   
    int x1 = -1, y1 = -1, x2 = 6, y2 = 6;
	Segment<int> testSeg1(x1, y1, x2, y2);
    Point<int> testPoint(2, 2);
    EXPECT_TRUE(testSeg1.colinear(testPoint));
}

TEST(IntSegment, IntersectionTest1)
{   
    int axis = -7;
    Point<int> point0(2, -3);
    Point<int> point1(2, -10);
	Segment<int> testSeg(point0, point1);
    EXPECT_TRUE(testSeg.checkIntersection(axis));
    double xValue = 2.0;
    EXPECT_TRUE(fabs(testSeg.getIntersection(axis) - xValue) < 1E-6);
}


TEST(IntSegment, NonIntersectionTest1)
{   
    int axis = -7;
    Point<int> point0(4, -7);
    Point<int> point1(6, -9);
	Segment<int> testSeg(point0, point1);
    EXPECT_FALSE(testSeg.checkIntersection(axis));
}


TEST(IntSegment, IntersectionTest2)
{   
    int axis = -7;
    Point<int> point0(6, -7);
    Point<int> point1(7, -2);
	Segment<int> testSeg(point0, point1);
    EXPECT_TRUE(testSeg.checkIntersection(axis));
    double xValue = 6.0;
    EXPECT_TRUE(fabs(testSeg.getIntersection(axis) - xValue) < 1E-6);
}


TEST(IntSegment, NonIntersectionTest2)
{   
    int axis = -7;
    Point<int> point0(6, -11);
    Point<int> point1(8, -7);
	Segment<int> testSeg(point0, point1);
    EXPECT_FALSE(testSeg.checkIntersection(axis));
}


TEST(IntSegment, IntersectionTest3)
{   
    int axis = -7;
    Point<int> point0(8, -6);
    Point<int> point1(11, -7);
	Segment<int> testSeg(point0, point1);
    EXPECT_TRUE(testSeg.checkIntersection(axis));
    double xValue = 11.0;
    EXPECT_TRUE(fabs(testSeg.getIntersection(axis) - xValue) < 1E-6);
}


TEST(IntSegment, IntersectionTest4)
{   
    int axis = -7;
    Point<int> point0(14, -9);
    Point<int> point1(22, -5);
	Segment<int> testSeg(point0, point1);
    EXPECT_TRUE(testSeg.checkIntersection(axis));
    double xValue = 18.0;
    EXPECT_TRUE(fabs(testSeg.getIntersection(axis) - xValue) < 1E-6);
}

TEST(IntSegment, NonIntersectionTest3)
{   
    int axis = -7;
    Point<int> point0(20, -9);
    Point<int> point1(22, -11);
	Segment<int> testSeg(point0, point1);
    EXPECT_FALSE(testSeg.checkIntersection(axis));
}

TEST(IntSegment, NonIntersectionTest4)
{   
    int axis = -7;
    Point<int> point0(20, -10);
    Point<int> point1(22, -8);
	Segment<int> testSeg(point0, point1);
    EXPECT_FALSE(testSeg.checkIntersection(axis));
}

TEST(IntSegment, NonIntersectionTest5)
{   
    int axis = -7;
    Point<int> point0(20, 1);
    Point<int> point1(22, -6);
	Segment<int> testSeg(point0, point1);
    EXPECT_FALSE(testSeg.checkIntersection(axis));
}

TEST(IntSegment, NonIntersectionTest6)
{   
    int axis = -7;
    Point<int> point0(20, -5);
    Point<int> point1(22, -3);
	Segment<int> testSeg(point0, point1);
    EXPECT_FALSE(testSeg.checkIntersection(axis));
}
