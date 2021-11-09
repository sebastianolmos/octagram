#include <gtest/gtest.h>
#include"octagram/vector.hpp"
#include"octagram/point.hpp"
#include <math.h> 
#include<string> 
using namespace std;

bool isEqual(float x1, float x2, float epsilon)
{
    return fabs(x1 - x2) <= ( (fabs(x1) < fabs(x2) ? fabs(x2) : fabs(x1)) * epsilon);
}

TEST(FloatVector, ConstructorTest)
{   
    Vector<float>* testVec = new Vector<float>();
    EXPECT_TRUE(isEqual(testVec->getX(), 0.0f, 1E-6));
    EXPECT_TRUE(isEqual(testVec->getY(), 0.0f, 1E-6));
    EXPECT_TRUE(isEqual(testVec->getZ(), 0.0f, 1E-6));
    delete testVec;
}

TEST(FloatVector, GetXTest)
{   
    float x = 32.0f;
    Vector<float>* testVec = new Vector<float>(x, 0.0f, 0.0f);
    EXPECT_TRUE(isEqual(testVec->getX(), x, 1E-6));
    delete testVec;
}

TEST(FloatVector, GetYTest)
{   
    float y = 43.0f;
    Vector<float>* testVec = new Vector<float>(0.0f, y, 0.0f);
    EXPECT_TRUE(isEqual(testVec->getY(), y, 1E-6));
    delete testVec;
}

TEST(FloatVector, GetZTest)
{   
    float z = 32.0f;
    Vector<float>* testVec = new Vector<float>(0.0f, 0.0f, z);
    EXPECT_TRUE(isEqual(testVec->getZ(), z, 1E-6));
    delete testVec;
}

TEST(FloatVector, StringTest)
{   
    float x1 = -60.1f, y1 = 98.4f, z1 = 3.6f;
	Vector<float> testVec1(x1, y1, z1);
    stringstream out;
    out << testVec1;
    EXPECT_TRUE(out.str() == "V(-60.1, 98.4, 3.6)");
}

TEST(FloatVector, EqualTest)
{   
    float x1 = -325.0f, y1 = 1.0f, z1 = 336.0f;
	float x2 = -325.0f, y2 = 1.0f, z2 = 336.0f;
	Vector<float> testVector1(x1, y1, z1);
	Vector<float> testVector2(x2, y2, z2);
    ASSERT_TRUE(testVector1 == testVector2);
}

TEST(FloatVector, NotEqualTest)
{   
    float x1 = -325.0f, y1 = 1.0f, z1 = 336.0f;
	float x2 = 325.0f, y2 = 1024.0f, z2 = 336.0f;
	Vector<float> testVector1(x1, y1, z1);
	Vector<float> testVector2(x2, y2, z2);
    ASSERT_FALSE(testVector1 == testVector2);
}

TEST(FloatVector, CopyTest)
{   
    float x1 = -100.0f, y1 = 69.0f, z1 = 999.0f;
	Vector<float> testVector1(x1, y1, z1);
	Vector<float> testVector2 = testVector1;
    EXPECT_TRUE(testVector1 == testVector2);
}

TEST(FloatVector, ConstructorPointsTest)
{   
    float x1 = 5.0f, y1 = 3.0f;
	float x2 = 3.0f, y2 = 8.0f;
    Point<float> testPoint1(x1, y1);
	Point<float> testPoint2(x2, y2);
    Vector<float> resultVector(testPoint1, testPoint2);
	Vector<float> expectedVector(-2.0f, 5.0f, 0.0f);
    EXPECT_TRUE(resultVector == expectedVector);
}

TEST(FloatVector, AddTest)
{   
    float x1 = -8.0f, y1 = 1.0f, z1 = 47.0f;
	float x2 = 39.0f, y2 = -2048.0f, z2 = 0.0f;
	Vector<float> testVector1(x1, y1, z1);
	Vector<float> testVector2(x2, y2, z2);
	Vector<float> testVector3(31.0f, -2047.0f, 47.0f);
	Vector<float> testVector4 = testVector1 + testVector2;
    EXPECT_TRUE(testVector4 == testVector3);
}

TEST(FloatVector, SubstTest)
{   
    float x1 = -8.0f, y1 = 1.0f, z1 = 47.0f;
	float x2 = 39.0f, y2 = -2048.0f, z2 = 0.0f;
	Vector<float> testVector1(x1, y1, z1);
	Vector<float> testVector2(x2, y2, z2);
	Vector<float> testVector3(-47.0f, 2049.0f, 47.0f);
	Vector<float> testVector4 = testVector1 - testVector2;
    EXPECT_TRUE(testVector4 == testVector3);
}

TEST(FloatVector, ScaleTest)
{   
    float x1 = -8.0f, y1 = 1.0f, z1 = 47.0f;
	float scale = 3.0f;
	Vector<float> testVector1(x1, y1, z1);
	Vector<float> testVector2(-24.0f, 3.0f, 141.0f);
	Vector<float> testVector3 = testVector1 * scale;
    EXPECT_TRUE(testVector3 == testVector2);
}

TEST(FloatVector, DotTest)
{   
    float x1 = 2.0f, y1 = -1.0f, z1 = 20.0f;
	float x2 = 0.0f, y2 = 4.0f, z2 = 4.0f;
	Vector<float> testVector1(x1, y1, z1);
	Vector<float> testVector2(x2, y2, z2);
	float result = testVector1.dot(testVector2);
	float expected = 76.0f;
    EXPECT_TRUE(isEqual(result, expected, 1E-6));
}

TEST(FloatVector, CrossTest)
{   
	float x1 = 1.0f, y1 = 0.0f, z1 = 0.0f;
	float x2 = 0.0f, y2 = 1.0f, z2 = 0.0f;
	Vector<float> testVector1(x1, y1, z1);
	Vector<float> testVector2(x2, y2, z2);
	Vector<float> resultVector = testVector1.cross(testVector2);
	Vector<float> expectedVector(0.0f, 0.0f, 1.0f);
    EXPECT_TRUE(resultVector == expectedVector);
}

TEST(FloatVector, Magnitude2Test)
{   
    float x1 = 5.0f, y1 = 7.0f, z1 = -3.0f;
	Vector<float> testVector1(x1, y1, z1);
    float expected = 83;
    EXPECT_TRUE(isEqual(testVector1.getMagnitude2(), expected, 1E-6));
}

TEST(FloatVector, MagnitudeTest)
{   
    float x1 = 40.0f, y1 = 0.0f, z1 = 30.0f;
	Vector<float> testVector1(x1, y1, z1);
    EXPECT_TRUE(isEqual(testVector1.getMagnitude(), 50.0f, 1E-6));
}

TEST(FloatVector, NormalizeTest)
{   
    float x1 = 3.0f, y1 = 4.0f, z1 = 0.0f;
	Vector<float> testVec1(x1, y1, z1);
	testVec1.normalize();
	Vector<float> expectedVec1(0.6, 0.8, 0);
    EXPECT_TRUE(testVec1 == expectedVec1);
}

TEST(FloatVector, SetTest)
{   
    float x1 = -43.0f, y1 = 20.0f, z1 = 12.0f;
	Vector<float> testVector1(0.0f, 0.0f, 0.0f);
	Vector<float> testVector2(x1, y1, z1);
	testVector1.set(x1, y1, z1);
    EXPECT_TRUE(testVector1 == testVector2);
}