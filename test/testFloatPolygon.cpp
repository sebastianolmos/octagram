#include <gtest/gtest.h>
#include"octagram/polygon.hpp"
#include"octagram/point.hpp"
#include<string> 
#include <math.h> 
using namespace std;

bool isEqual(float x1, float x2, float epsilon)
{
    return fabs(x1 - x2) <= ( (fabs(x1) < fabs(x2) ? fabs(x2) : fabs(x1)) * epsilon);
}

TEST(FloatPolygon, ConstructorTest)
{   
    Polygon<float>* testP = new Polygon<float>();
    ASSERT_TRUE(testP->getCount() == 0.0f);
    ASSERT_TRUE(testP->getArea2() == 0.0f);
    ASSERT_FALSE(testP->isCCW());
    Point<float> dummyPoint(0.0f, 0.0f);
    ASSERT_FALSE(testP->isInBorder(dummyPoint));
    delete testP;

    Polygon<float>* testP1 = new Polygon<float>(dummyPoint);
    ASSERT_TRUE(testP1->getCount() == 1);
    delete testP1;
}

TEST(FloatPolygon, addPointTest)
{   
    Polygon<float> p1;

    Point<float> point0(1.0f, 2.0f);
	p1.addPoint(point0);
    EXPECT_EQ(1, p1.getCount());

    Point<float> point1(-1.0f, 2.0f);
	p1.addPoint(point1);
    EXPECT_EQ(2, p1.getCount());
}

TEST(FloatPolygon, StringTest)
{   
    Polygon<float> p1;

    Point<float> point0(1.1f, 2.2f);
	p1.addPoint(point0);

    Point<float> point1(-1.3f, 2.4f);
	p1.addPoint(point1);

    stringstream out;
    out << p1;
    EXPECT_TRUE(out.str() == "Polygon(P(1.1, 2.2), P(-1.3, 2.4))");
}

TEST(FloatPolygon, getAreaTest1)
{   
    Polygon<float> testPoly;
	Point<float> p0(0.0f, 0.0f);
	testPoly.addPoint(p0);

	Point<float> p1(50.0f, 0.0f);
	testPoly.addPoint(p1);

	Point<float> p2(50.0f, 20.0f);
	testPoly.addPoint(p2);

	Point<float> p3(0.0f, 20.0f);
	testPoly.addPoint(p3);

    EXPECT_TRUE(isEqual(testPoly.getArea2(), 2000.0f, 1E-6));
    EXPECT_TRUE(isEqual(testPoly.getArea(), 1000.0f, 1E-6));
}

TEST(FloatPolygon, getAreaTest2)
{   
    Polygon<float> testPoly;

	Point<float> p0(-10.0f, -10);
	testPoly.addPoint(p0);

	Point<float> p1(10.0f, -10.0f);
	testPoly.addPoint(p1);

	Point<float> p2(0.0f, 10.0f);
	testPoly.addPoint(p2);

    EXPECT_TRUE(isEqual(testPoly.getArea2(), 400.0f, 1E-6));
    EXPECT_TRUE(isEqual(testPoly.getArea(), 200.0f, 1E-6));
}

TEST(FloatPolygon, getAreaTest3)
{   
    Polygon<float> testPoly;

	Point<float> p0(0.0f, -2.0f);
	testPoly.addPoint(p0);

	Point<float> p1(6.0f, -2.0f);
	testPoly.addPoint(p1);

	Point<float> p2(9.0f, -0.0f);
	testPoly.addPoint(p2);

	Point<float> p3(6.0f, 2.0f);
	testPoly.addPoint(p3);

	Point<float> p4(9.0f, 4.0f);
	testPoly.addPoint(p4);

	Point<float> p5(4.0f, 7.0f);
	testPoly.addPoint(p5);

	Point<float> p6(-1.0f, 6.0f);
	testPoly.addPoint(p6);

	Point<float> p7(-3.0f, 3.0f);
	testPoly.addPoint(p7);

    EXPECT_TRUE(isEqual(testPoly.getArea2(), 153.0f, 1E-6));
    EXPECT_TRUE(isEqual(testPoly.getArea(), 76.5f, 1E-6));
}

TEST(FloatPolygon, CCWTest1)
{   
    Polygon<float> testPoly;

	Point<float> p0(0.0f, 0.0f);
	testPoly.addPoint(p0);

	Point<float> p1(50.0f, 0.0f);
	testPoly.addPoint(p1);

	Point<float> p2(50.0f, 20.0f);
	testPoly.addPoint(p2);

	Point<float> p3(0.0f, 20.0f);
	testPoly.addPoint(p3);

	EXPECT_TRUE(testPoly.isCCW());
}

TEST(FloatPolygon, CCWTest2)
{   
    Polygon<float> testPoly;

    Point<float> p0(-10.0f, -10.0f);
	testPoly.addPoint(p0);

	Point<float> p2(0.0f, 10.0f);
	testPoly.addPoint(p2);

	Point<float> p1(10.0f, -10.0f);
	testPoly.addPoint(p1);

	EXPECT_FALSE(testPoly.isCCW());
}

TEST(FloatPolygon, CCWTest3)
{   
    Polygon<float> testPoly;

	Point<float> p0(0.0f, -2.0f);
	testPoly.addPoint(p0);

	Point<float> p1(6.0f, -2.0f);
	testPoly.addPoint(p1);

	Point<float> p2(9.0f, -0.0f);
	testPoly.addPoint(p2);

	Point<float> p3(6.0f, 2.0f);
	testPoly.addPoint(p3);

	Point<float> p4(9.0f, 4.0f);
	testPoly.addPoint(p4);

	Point<float> p5(4.0f, 7.0f);
	testPoly.addPoint(p5);

	Point<float> p6(-1.0f, 6.0f);
	testPoly.addPoint(p6);

	Point<float> p7(-3.0f, 3.0f);
	testPoly.addPoint(p7);

	EXPECT_TRUE(testPoly.isCCW());
}

TEST(FloatPolygon, BorderTest)
{   
    Polygon<float> testPoly;

    Point<float> p0(3.0f, -1.0f);
	testPoly.addPoint(p0);

	Point<float> p2(0.0f, 2.0f);
	testPoly.addPoint(p2);

	Point<float> p1(-2.0f, -1.0f);
	testPoly.addPoint(p1);

    Point<float> q1(1.0f, -1.0f);
    Point<float> q2(0.0f, 0.0f);
    Point<float> q3(0.0f, -3.0f);

    EXPECT_TRUE(testPoly.isInBorder(q1));
    EXPECT_FALSE(testPoly.isInBorder(q2));
    EXPECT_FALSE(testPoly.isInBorder(q3));
}

TEST(FloatPolygon, InsideTest1)
{   
    Polygon<float> testPoly;

	Point<float> p0(1.0f, 5.0f);
	testPoly.addPoint(p0);

	Point<float> p1(0.0f, 2.0f);
	testPoly.addPoint(p1);

	Point<float> p2(2.0f, 0.0f);
	testPoly.addPoint(p2);

	Point<float> p3(4.0f, 1.0f);
	testPoly.addPoint(p3);

	Point<float> p4(5.0f, 3.0f);
	testPoly.addPoint(p4);

    Point<float> q1(2.0f, 3.0f);
    Point<float> q2(1.0f, 5.0f);
    Point<float> q3(3.0f, 4.0f);

    Point<float> r1(-1.0f, 4.0f);
    Point<float> r2(6.0f, 1.0f);

    EXPECT_TRUE(testPoly.isInside(q1));
    EXPECT_TRUE(testPoly.isInside(q2));
    EXPECT_TRUE(testPoly.isInside(q3));

    EXPECT_FALSE(testPoly.isInside(r1));
    EXPECT_FALSE(testPoly.isInside(r2));
}

TEST(FloatPolygon, InsideTest2)
{   
    Polygon<float> testPoly;

	Point<float> p0(-2.0f, 0.0f);
	testPoly.addPoint(p0);

	Point<float> p1(-4.0f, -3.0f);
	testPoly.addPoint(p1);

	Point<float> p2(-2.0f, -6.0f);
	testPoly.addPoint(p2);

	Point<float> p3(2.0f, -3.0f);
	testPoly.addPoint(p3);

	Point<float> p4(-1.0f, -3.0f);
	testPoly.addPoint(p4);

    Point<float> q1(-2.0f, -3.0f);
    Point<float> q2(1.0f, -3.0f);

    Point<float> r1(-5.0f, 3.0f);
    Point<float> r2(0.0f, -2.0f);

    EXPECT_TRUE(testPoly.isInside(q1));
    EXPECT_TRUE(testPoly.isInside(q2));

    EXPECT_FALSE(testPoly.isInside(r1));
    EXPECT_FALSE(testPoly.isInside(r2));
}

TEST(FloatPolygon, InsideTest3)
{   
    Polygon<float> testPoly;

	Point<float> p0(-4.0f, 5.0f);
	testPoly.addPoint(p0);

	Point<float> p1(-5.0f, 1.0f);
	testPoly.addPoint(p1);

	Point<float> p2(0.0f, -2.0f);
	testPoly.addPoint(p2);

	Point<float> p3(4.0f, 2.0f);
	testPoly.addPoint(p3);

	Point<float> p4(3.0f, 5.0f);
	testPoly.addPoint(p4);

    Point<float> p5(-1.0f, 2.0f);
	testPoly.addPoint(p5);

    Point<float> q1(-4.0f, 3.0f);
    Point<float> q2(2.0f, 3.0f);
    Point<float> q3(0.0f, -1.0f);

    Point<float> r1(-5.0f, 4.0f);
    Point<float> r2(-1.0f, 4.0f);
    Point<float> r3(4.0f, 4.0f);

    EXPECT_TRUE(testPoly.isInside(q1));
    EXPECT_TRUE(testPoly.isInside(q2));
    EXPECT_TRUE(testPoly.isInside(q3));

    EXPECT_FALSE(testPoly.isInside(r1));
    EXPECT_FALSE(testPoly.isInside(r2));
    EXPECT_FALSE(testPoly.isInside(r3));
}

TEST(FloatPolygon, EqualTest1)
{   
    Polygon<float> poly1;
	poly1.addPoint(Point<float>(-4.0f, 5.0f));
	poly1.addPoint(Point<float>(-5.0f, 1.0f));
	poly1.addPoint(Point<float>( 0.0f,-2.0f));
	poly1.addPoint(Point<float>( 4.0f, 2.0f));
	poly1.addPoint(Point<float>( 3.0f, 5.0f));
	poly1.addPoint(Point<float>(-1.0f, 2.0f));

	Polygon<float> poly2;
	poly2.addPoint(Point<float>(-4.0f, 5.0f));
	poly2.addPoint(Point<float>(-5.0f, 1.0f));
	poly2.addPoint(Point<float>( 0.0f,-2.0f));
	poly2.addPoint(Point<float>( 4.0f, 2.0f));
	poly2.addPoint(Point<float>( 3.0f, 5.0f));
	poly2.addPoint(Point<float>(-1.0f, 2.0f));

    EXPECT_TRUE(poly1 == poly2);
}

TEST(FloatPolygon, EqualTest2)
{   
    Polygon<float> poly1;
	poly1.addPoint(Point<float>(-4.0f, 5.0f));
	poly1.addPoint(Point<float>(-5.0f, 1.0f));
	poly1.addPoint(Point<float>( 0.0f,-2.0f));
	poly1.addPoint(Point<float>( 4.0f, 2.0f));
	poly1.addPoint(Point<float>( 3.0f, 5.0f));
	poly1.addPoint(Point<float>(-1.0f, 2.0f));

	Polygon<float> poly2;
	poly2.addPoint(Point<float>( 4.0f, 2.0f));
	poly2.addPoint(Point<float>( 3.0f, 5.0f));
	poly2.addPoint(Point<float>(-1.0f, 2.0f));
	poly2.addPoint(Point<float>(-4.0f, 5.0f));
	poly2.addPoint(Point<float>(-5.0f, 1.0f));
	poly2.addPoint(Point<float>( 0.0f,-2.0f));

    EXPECT_TRUE(poly1 == poly2);
}

TEST(FloatPolygon, NotEqualTest1)
{   
    Polygon<float> poly1;
	poly1.addPoint(Point<float>(-4.0f, 5.0f));
	poly1.addPoint(Point<float>(-5.0f, 1.0f));
	poly1.addPoint(Point<float>( 0.0f,-2.0f));
	poly1.addPoint(Point<float>( 4.0f, 2.0f));
	poly1.addPoint(Point<float>( 3.0f, 5.0f));
	poly1.addPoint(Point<float>(-1.0f, 2.0f));

	Polygon<float> poly2;
	poly2.addPoint(Point<float>( 4.0f, 2.0f));
	poly2.addPoint(Point<float>( 3.0f, 5.0f));
	poly2.addPoint(Point<float>(-1.0f, 2.0f));
	poly2.addPoint(Point<float>(-4.0f, 5.0f));

    EXPECT_FALSE(poly1 == poly2);
}

TEST(FloatPolygon, NotEqualTest2)
{   
    Polygon<float> poly1;
	poly1.addPoint(Point<float>(-4.0f, 5.0f));
	poly1.addPoint(Point<float>(-5.0f, 1.0f));
	poly1.addPoint(Point<float>( 0.0f,-2.0f));
	poly1.addPoint(Point<float>( 4.0f, 2.0f));
	poly1.addPoint(Point<float>( 3.0f, 5.0f));
	poly1.addPoint(Point<float>(-1.0f, 2.0f));

	Polygon<float> poly2;
	poly2.addPoint(Point<float>( 4.0f, 2.0f));
	poly2.addPoint(Point<float>( 3.0f, 5.0f));
	poly2.addPoint(Point<float>(-1.0f, 2.0f));
	poly2.addPoint(Point<float>(-4.0f, 5.0f));
	poly2.addPoint(Point<float>( 0.0f,-2.0f));
	poly2.addPoint(Point<float>(-5.0f, 1.0f));

    EXPECT_FALSE(poly1 == poly2);
}