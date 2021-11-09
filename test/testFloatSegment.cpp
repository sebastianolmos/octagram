#include <gtest/gtest.h>
#include"octagram/segment.hpp"
#include"octagram/point.hpp"
#include <math.h> 
#include<string> 
using namespace std;

bool isEqual(float x1, float x2, float epsilon)
{
    return fabs(x1 - x2) <= ( (fabs(x1) < fabs(x2) ? fabs(x2) : fabs(x1)) * epsilon);
}

TEST(FloatSegment, ConstructorTest)
{   
    Segment<float>* testSeg = new Segment<float>();
    Point<float> zeroPoint(0.0f, 0.0f);
    ASSERT_TRUE(zeroPoint == testSeg->getOrigin());
    ASSERT_TRUE(zeroPoint == testSeg->getEnd());
    delete testSeg;

    float x1 = -65.0f, y1 = 43.0f;
	float x2 = 16.0f, y2 = -9.0f;
    Point<float> testPoint1(x1, y1);
	Point<float> testPoint2(x2, y2);
    Segment<float>* testSeg1 = new Segment<float>(x1, y1, x2, y2);
    ASSERT_TRUE(testPoint1 == testSeg1->getOrigin());
    ASSERT_TRUE(testPoint2 == testSeg1->getEnd());
    delete testSeg1;
}

TEST(FloatSegment, EqualTest)
{   
    Point<float> testPoint1(0.0f, -4.0f);
	Point<float> testPoint2(10.0f, 25.0f);
    Point<float> testPoint3(0.0f, -4.0f);
	Segment<float> testSeg1(testPoint1, testPoint2);
	Segment<float> testSeg2(testPoint3, testPoint2);
    ASSERT_TRUE(testSeg1 == testSeg2);
}

TEST(FloatSegment, NotEqualTest)
{   
    Point<float> testPoint1(0.0f, -4.0f);
	Point<float> testPoint2(10.0f, 25.0f);
    Point<float> testPoint3(-2.0f, -4.0f);
	Segment<float> testSeg1(testPoint1, testPoint2);
	Segment<float> testSeg2(testPoint3, testPoint2);
    ASSERT_FALSE(testSeg1 == testSeg2);
}

TEST(FloatSegment, PointsConstructorTest)
{   
    float x1 = 5.0f, y1 = 3.0f;
	float x2 = 3.0f, y2 = 8.0f;
    Point<float> testPoint1(x1, y1);
	Point<float> testPoint2(x2, y2);
    Segment<float> resultSeg(testPoint1, testPoint2);
	Segment<float> expectedSeg(x1, y1, x2, y2);
    EXPECT_TRUE(resultSeg == expectedSeg);
}

TEST(FloatSegment, getOriginTest)
{   
    Point<float> testPoint(10.0f, 20.0f);
    Point<float> zeroPoint(0.0f, 0.0f);
    Segment<float>* testSeg = new Segment<float>(testPoint, zeroPoint);
    EXPECT_TRUE(testPoint == testSeg->getOrigin());
    EXPECT_TRUE(zeroPoint == testSeg->getEnd());
    delete testSeg;
}

TEST(FloatSegment, getEndTest)
{   
    Point<float> testPoint(10.0f, 20.0f);
    Point<float> zeroPoint(0.0f, 0.0f);
    Segment<float>* testSeg = new Segment<float>(zeroPoint, testPoint);
    EXPECT_TRUE(zeroPoint == testSeg->getOrigin());
    EXPECT_TRUE(testPoint == testSeg->getEnd());
    delete testSeg;
}

TEST(FloatSegment, setOriginTest)
{   
    Point<float> testPoint(10.0f, 20.0f);
    Point<float> zeroPoint(0.0f, 0.0f);
    Segment<float>* testSeg = new Segment<float>();
    EXPECT_TRUE(zeroPoint == testSeg->getOrigin());
    EXPECT_TRUE(zeroPoint == testSeg->getEnd());

    testSeg->setOrigin(testPoint);
    EXPECT_TRUE(testPoint == testSeg->getOrigin());
    EXPECT_TRUE(zeroPoint == testSeg->getEnd());
    delete testSeg;
}

TEST(FloatSegment, setEndTest)
{   
    Point<float> testPoint(10.0f, 20.0f);
    Point<float> zeroPoint(0.0f, 0.0f);
    Segment<float>* testSeg = new Segment<float>();
    EXPECT_TRUE(zeroPoint == testSeg->getOrigin());
    EXPECT_TRUE(zeroPoint == testSeg->getEnd());

    testSeg->setEnd(testPoint);
    EXPECT_TRUE(zeroPoint == testSeg->getOrigin());
    EXPECT_TRUE(testPoint == testSeg->getEnd());
    delete testSeg;
}

TEST(FloatSegment, StringTest)
{   
    float x1 = -60.1f, y1 = 98.2f, x2 = 3.3f, y2 = 100.4f;
	Segment<float> testSeg1(x1, y1, x2, y2);
    stringstream out;
    out << testSeg1;
    EXPECT_TRUE(out.str() == "S(From P(-60.1, 98.2) to P(3.3, 100.4))");
}

TEST(FloatSegment, getLength2Test)
{   
    float x1 = 2.0f, y1 = 1.0f, x2 = 5.0f, y2 = 5.0f;
	Segment<float> testSeg1(x1, y1, x2, y2);
    EXPECT_TRUE(isEqual(testSeg1.getLength2(), 25.0f, 1E-6));
}

TEST(FloatSegment, getLengthTest)
{   
    float x1 = 0.0f, y1 = 1.0f, x2 = 6.0f, y2 = 5.0f;
	Segment<float> testSeg1(x1, y1, x2, y2);
    float result = sqrt(52.0f);
    EXPECT_TRUE(isEqual(testSeg1.getLength(), result, 1E-6));
}

TEST(FloatSegment, leftTest)
{   
    float x1 = -1.0f, y1 = -1.0f, x2 = 5.0f, y2 = 3.0f;
	Segment<float> testSeg1(x1, y1, x2, y2);
    Point<float> testPoint(0.0f, 0.0f);
    EXPECT_TRUE(testSeg1.left(testPoint));
    EXPECT_FALSE(testSeg1.right(testPoint));
}

TEST(FloatSegment, rigthTest)
{   
    float x1 = -1.0f, y1 = -1.0f, x2 = 5.0f, y2 = 6.0f;
	Segment<float> testSeg1(x1, y1, x2, y2);
    Point<float> testPoint(4.0f, 0.0f);
    EXPECT_TRUE(testSeg1.right(testPoint));
    EXPECT_FALSE(testSeg1.left(testPoint));
}

TEST(FloatSegment, colinearTest)
{   
    float x1 = -1.0f, y1 = -1.0f, x2 = 6.0f, y2 = 6.0f;
	Segment<float> testSeg1(x1, y1, x2, y2);
    Point<float> testPoint(2.0f, 2.0f);
    EXPECT_TRUE(testSeg1.colinear(testPoint));
}

TEST(FloatSegment, IntersectionTest1)
{   
    float axis = -7.0f;
    Point<float> point0(2.0f, -3.0f);
    Point<float> point1(2.0f, -10.0f);
	Segment<float> testSeg(point0, point1);
    EXPECT_TRUE(testSeg.checkIntersection(axis));
    double xValue = 2.0;
    EXPECT_TRUE(isEqual(testSeg.getIntersection(axis), xValue, 1E-6));
}


TEST(FloatSegment, NonIntersectionTest1)
{   
    float axis = -7.0f;
    Point<float> point0(4.0f, -7.0f);
    Point<float> point1(6.0f, -9.0f);
	Segment<float> testSeg(point0, point1);
    EXPECT_FALSE(testSeg.checkIntersection(axis));
}


TEST(FloatSegment, IntersectionTest2)
{   
    float axis = -7.0f;
    Point<float> point0(6.0f, -7.0f);
    Point<float> point1(7.0f, -2.0f);
	Segment<float> testSeg(point0, point1);
    EXPECT_TRUE(testSeg.checkIntersection(axis));
    double xValue = 6.0;
    EXPECT_TRUE(isEqual(testSeg.getIntersection(axis), xValue, 1E-6));
}


TEST(FloatSegment, NonIntersectionTest2)
{   
    float axis = -7.0f;
    Point<float> point0(6.0f, -11.0f);
    Point<float> point1(8.0f, -7.0f);
	Segment<float> testSeg(point0, point1);
    EXPECT_FALSE(testSeg.checkIntersection(axis));
}


TEST(FloatSegment, IntersectionTest3)
{   
    float axis = -7.0f;
    Point<float> point0(8.0f, -6.0f);
    Point<float> point1(11.0f, -7.0f);
	Segment<float> testSeg(point0, point1);
    EXPECT_TRUE(testSeg.checkIntersection(axis));
    double xValue = 11.0;
    EXPECT_TRUE(isEqual(testSeg.getIntersection(axis), xValue, 1E-6));
}


TEST(FloatSegment, IntersectionTest4)
{   
    float axis = -7.0f;
    Point<float> point0(14.0f, -9.0f);
    Point<float> point1(22.0f, -5.0f);
	Segment<float> testSeg(point0, point1);
    EXPECT_TRUE(testSeg.checkIntersection(axis));
    float xValue = 18.0;
    EXPECT_TRUE(isEqual(testSeg.getIntersection(axis), xValue, 1E-6));
}

TEST(FloatSegment, NonIntersectionTest3)
{   
    float axis = -7.0f;
    Point<float> point0(20, -9.0f);
    Point<float> point1(22.0f, -11.0f);
	Segment<float> testSeg(point0, point1);
    EXPECT_FALSE(testSeg.checkIntersection(axis));
}

TEST(FloatSegment, NonIntersectionTest4)
{   
    float axis = -7.0f;
    Point<float> point0(20.0f, -10.0f);
    Point<float> point1(22.0f, -8.0f);
	Segment<float> testSeg(point0, point1);
    EXPECT_FALSE(testSeg.checkIntersection(axis));
}

TEST(FloatSegment, NonIntersectionTest5)
{   
    float axis = -7.0f;
    Point<float> point0(20.0f, 1.0f);
    Point<float> point1(22.0f, -6.0f);
	Segment<float> testSeg(point0, point1);
    EXPECT_FALSE(testSeg.checkIntersection(axis));
}

TEST(FloatSegment, NonIntersectionTest6)
{   
    float axis = -7.0f;
    Point<float> point0(20.0f, -5.0f);
    Point<float> point1(22.0f, -3.0f);
	Segment<float> testSeg(point0, point1);
    EXPECT_FALSE(testSeg.checkIntersection(axis));
}
