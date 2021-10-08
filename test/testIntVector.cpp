#include <gtest/gtest.h>
#include"octagram/vector.hpp"
#include"octagram/point.hpp"
#include<string> 
using namespace std;

TEST(IntVector, ConstructorTest)
{   
    Vector<int>* testVec = new Vector<int>();
    EXPECT_TRUE(testVec->getX() == 0);
    EXPECT_TRUE(testVec->getY() == 0);
    EXPECT_TRUE(testVec->getZ() == 0);
    delete testVec;
}

TEST(IntVector, GetXTest)
{   
    int x = 32;
    Vector<int>* testVec = new Vector<int>(x, 0, 0);
    EXPECT_TRUE(testVec->getX() == x);
    delete testVec;
}

TEST(IntVector, GetYTest)
{   
    int y = 43;
    Vector<int>* testVec = new Vector<int>(0, y, 0);
    EXPECT_TRUE(testVec->getY() == y);
    delete testVec;
}

TEST(IntVector, GetZTest)
{   
    int z = 32;
    Vector<int>* testVec = new Vector<int>(0, 0, z);
    EXPECT_TRUE(testVec->getZ() == z);
    delete testVec;
}

TEST(IntVector, StringTest)
{   
    int x1 = -60, y1 = 98, z1 = 3;
	Vector<int> testVec1(x1, y1, z1);
    stringstream out;
    out << testVec1;
    EXPECT_TRUE(out.str() == "V(-60, 98, 3)");
}

TEST(IntVector, EqualTest)
{   
    int x1 = -325, y1 = 1, z1 = 336;
	int x2 = -325, y2 = 1, z2 = 336;
	Vector<int> testVector1(x1, y1, z1);
	Vector<int> testVector2(x2, y2, z2);
    ASSERT_TRUE(testVector1 == testVector2);
}

TEST(IntVector, NotEqualTest)
{   
    int x1 = -325, y1 = 1, z1 = 336;
	int x2 = 325, y2 = 1024, z2 = 336;
	Vector<int> testVector1(x1, y1, z1);
	Vector<int> testVector2(x2, y2, z2);
    ASSERT_FALSE(testVector1 == testVector2);
}

TEST(IntVector, CopyTest)
{   
    int x1 = -100, y1 = 69, z1 = 999;
	Vector<int> testVector1(x1, y1, z1);
	Vector<int> testVector2 = testVector1;
    EXPECT_TRUE(testVector1 == testVector2);
}

TEST(IntVector, ConstructorPointsTest)
{   
    int x1 = 5, y1 = 3;
	int x2 = 3, y2 = 8;
    Point<int> testPoint1(x1, y1);
	Point<int> testPoint2(x2, y2);
    Vector<int> resultVector(testPoint1, testPoint2);
	Vector<int> expectedVector(-2, 5, 0);
    EXPECT_TRUE(resultVector == expectedVector);
}

TEST(IntVector, AddTest)
{   
    int x1 = -8, y1 = 1, z1 = 47;
	int x2 = 39, y2 = -2048, z2 = 0;
	Vector<int> testVector1(x1, y1, z1);
	Vector<int> testVector2(x2, y2, z2);
	Vector<int> testVector3(31, -2047, 47);
	Vector<int> testVector4 = testVector1 + testVector2;
    EXPECT_TRUE(testVector4 == testVector3);
}

TEST(IntVector, SubstTest)
{   
    int x1 = -8, y1 = 1, z1 = 47;
	int x2 = 39, y2 = -2048, z2 = 0;
	Vector<int> testVector1(x1, y1, z1);
	Vector<int> testVector2(x2, y2, z2);
	Vector<int> testVector3(-47, 2049, 47);
	Vector<int> testVector4 = testVector1 - testVector2;
    EXPECT_TRUE(testVector4 == testVector3);
}

TEST(IntVector, ScaleTest)
{   
    int x1 = -8, y1 = 1, z1 = 47;
	int scale = 3;
	Vector<int> testVector1(x1, y1, z1);
	Vector<int> testVector2(-24, 3, 141);
	Vector<int> testVector3 = testVector1 * scale;
    EXPECT_TRUE(testVector3 == testVector2);
}

TEST(IntVector, DotTest)
{   
    int x1 = 2, y1 = -1, z1 = 20;
	int x2 = 0, y2 = 4, z2 = 4;
	Vector<int> testVector1(x1, y1, z1);
	Vector<int> testVector2(x2, y2, z2);
	int result = testVector1.dot(testVector2);
	int expected = 76;
    EXPECT_TRUE(result == expected);
}

TEST(IntVector, CrossTest)
{   
	int x1 = 1, y1 = 0, z1 = 0;
	int x2 = 0, y2 = 1, z2 = 0;
	Vector<int> testVector1(x1, y1, z1);
	Vector<int> testVector2(x2, y2, z2);
	Vector<int> resultVector = testVector1.cross(testVector2);
	Vector<int> expectedVector(0, 0, 1);
    EXPECT_TRUE(resultVector == expectedVector);
}

TEST(IntVector, Magnitude2Test)
{   
    int x1 = 5, y1 = 7, z1 = -3;
	Vector<int> testVector1(x1, y1, z1);
    int expected = 83;
    EXPECT_TRUE(testVector1.getMagnitude2() == expected);
}

TEST(IntVector, MagnitudeTest)
{   
    int x1 = 40, y1 = 0, z1 = 30;
	Vector<int> testVector1(x1, y1, z1);
    EXPECT_TRUE(fabs(testVector1.getMagnitude() - 50.0f) < 1E-6);
}

TEST(IntVector, NormalizeTest)
{   
    int x1 = 0, y1 = 0, z1 = 33;
	Vector<int> testVec1(x1, y1, z1);
	testVec1.normalize();
	Vector<int> expectedVec1(0, 0, 1);
    EXPECT_TRUE(testVec1 == expectedVec1);

    int x2 = -4, y2 = 5, z2 = 1;
	Vector<int> testVec2(x2, y2, z2);
	testVec2.normalize();
	Vector<int> expectedVec2(0, 1, 0);
    EXPECT_TRUE(testVec2 == expectedVec2);

    int x3 = -20, y3 = 6, z3 = 12;
	Vector<int> testVec3(x3, y3, z3);
	testVec3.normalize();
	Vector<int> expectedVec3(-1, 0, 0);
    EXPECT_TRUE(testVec3 == expectedVec3);

    int x4 = 8, y4 = -5, z4 = 10;
	Vector<int> testVec4(x4, y4, z4);
	testVec4.normalize();
	Vector<int> expectedVec4(0, 0, 1);
    EXPECT_TRUE(testVec4 == expectedVec4);
}

TEST(IntVector, SetTest)
{   
    int x1 = -43, y1 = 20, z1 = 12;
	Vector<int> testVector1(0, 0, 0);
	Vector<int> testVector2(x1, y1, z1);
	testVector1.set(x1, y1, z1);
    EXPECT_TRUE(testVector1 == testVector2);
}