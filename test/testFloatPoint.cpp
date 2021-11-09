#include <gtest/gtest.h>
#include"octagram/point.hpp"
#include<string> 
#include <math.h> 
using namespace std;

bool isEqual(float x1, float x2, float epsilon)
{
    return fabs(x1 - x2) <= ( (fabs(x1) < fabs(x2) ? fabs(x2) : fabs(x1)) * epsilon);
}

TEST(FloatPoint, ConstructorTest)
{   
    Point<float>* testPoint = new Point<float>();
    EXPECT_TRUE(isEqual(testPoint->getX(), 0.0f, 1E-6));
    EXPECT_TRUE(isEqual(testPoint->getY(), 0.0f, 1E-6));
    delete testPoint;
}

TEST(FloatPoint, GetXTest)
{   
    float x = 32.0f;
    Point<float>* testPoint = new Point<float>(x, 0.0f);
    EXPECT_TRUE(isEqual(testPoint->getX(), x, 1E-6));
    delete testPoint;
}

TEST(FloatPoint, GetYTest)
{   
    float y = 43.0f;
    Point<float>* testPoint = new Point<float>(0.0f, y);
    EXPECT_TRUE(isEqual(testPoint->getY(), y, 1E-6));
    delete testPoint;
}

TEST(FloatPoint, StringTest)
{   
    float x1 = -60.4f, y1 = 98.7f;
	Point<float> testPoint1(x1, y1);
    stringstream out;
    out << testPoint1;
    cout <<testPoint1 << endl;
    EXPECT_TRUE(out.str() == "P(-60.4, 98.7)");
}

TEST(FloatPoint, EqualTest)
{   
    float x1 = -325.0f, y1 = 1.0f;
	float x2 = -325.0f, y2 = 1.0f;
	Point<float> testPoint1(x1, y1);
	Point<float> testPoint2(x2, y2);
    ASSERT_TRUE(testPoint1 == testPoint2);
}

TEST(FloatPoint, NotEqualTest)
{   
    float x1 = -325.0f, y1 = 1.0f;
	float x2 = 325.0f, y2 = 1024.0f;
	Point<float> testPoint1(x1, y1);
	Point<float> testPoint2(x2, y2);
    ASSERT_FALSE(testPoint1 == testPoint2);
}

TEST(FloatPoint, CopyTest)
{   
    float x1 = -100.0f, y1 = 69.0f;
	Point<float> testPoint1(x1, y1);
	Point<float> testPoint2 = testPoint1;
    EXPECT_TRUE(testPoint1 == testPoint2);
}

TEST(FloatPoint, AddTest)
{   
    float x1 = -8.0f, y1 = 1.0f;
	float x2 = 39.0f, y2 = -2048.0f;
	Point<float> testPoint1(x1, y1);
	Point<float> testPoint2(x2, y2);
    Point<float> testPoint3(31.0f, -2047.0f);
    Point<float> testPoint4 = testPoint1 + testPoint2;
    EXPECT_TRUE(testPoint4 == testPoint3);
}

TEST(FloatPoint, SubstTest)
{   
    float x1 = -8.0f, y1 = 1.0f;
	float x2 = 39.0f, y2 = -2048.0f;
	Point<float> testPoint1(x1, y1);
	Point<float> testPoint2(x2, y2);
    Point<float> testPoint3(-47.0f, 2049.0f);
    Point<float> testPoint4 = testPoint1 - testPoint2;
    EXPECT_TRUE(testPoint4 == testPoint3);
}

TEST(FloatPoint, ScaleTest)
{   
    float x1 = -8.0f, y1 = 1.0f;
	float scale = 3.0f;
	Point<float> testPoint1(x1, y1);
	Point<float> testPoint2(-24.0f, 3.0f);
    Point<float> testPoint3 = testPoint1 * scale;
    EXPECT_TRUE(testPoint3 == testPoint2);
}