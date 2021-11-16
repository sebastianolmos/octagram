#include <gtest/gtest.h>
#include"octagram/polygon.hpp"
#include"octagram/point.hpp"

TEST(intPolygon, ConstructorTest)
{   
    Polygon<int>* testP = new Polygon<int>();
    ASSERT_TRUE(testP->getCount() == 0);
    ASSERT_TRUE(testP->getArea2() == 0);
    ASSERT_FALSE(testP->isCCW());
    Point<int> dummyPoint(0, 0);
    ASSERT_FALSE(testP->isInBorder(dummyPoint));
    delete testP;

    Polygon<int>* testP1 = new Polygon<int>(dummyPoint);
    ASSERT_TRUE(testP1->getCount() == 1);
    delete testP1;
}

TEST(intPolygon, addPointTest)
{   
    Polygon<int> p1;

    Point<int> point0(1, 2);
	p1.addPoint(point0);
    EXPECT_EQ(1, p1.getCount());

    Point<int> point1(-1, 2);
	p1.addPoint(point1);
    EXPECT_EQ(2, p1.getCount());
}

TEST(intPolygon, StringTest)
{   
    Polygon<int> p1;

    Point<int> point0(1, 2);
	p1.addPoint(point0);

    Point<int> point1(-1, 2);
	p1.addPoint(point1);

    stringstream out;
    out << p1;
    EXPECT_TRUE(out.str() == "Polygon(P(1, 2), P(-1, 2))");
}

TEST(intPolygon, getAreaTest1)
{   
    Polygon<int> testPoly;
	Point<int> p0(0, 0);
	testPoly.addPoint(p0);

	Point<int> p1(50, 0);
	testPoly.addPoint(p1);

	Point<int> p2(50, 20);
	testPoly.addPoint(p2);

	Point<int> p3(0, 20);
	testPoly.addPoint(p3);

    EXPECT_EQ(testPoly.getArea2(), 2000);
    EXPECT_TRUE(fabs(testPoly.getArea() - 1000.0f) < 1E-5);
}

TEST(intPolygon, getAreaTest2)
{   
    Polygon<int> testPoly;

	Point<int> p0(-10, -10);
	testPoly.addPoint(p0);

	Point<int> p1(10, -10);
	testPoly.addPoint(p1);

	Point<int> p2(0, 10);
	testPoly.addPoint(p2);

    EXPECT_EQ(testPoly.getArea2(), 400);
    EXPECT_TRUE(fabs(testPoly.getArea() - 200.0f) < 1E-5);
}

TEST(intPolygon, getAreaTest3)
{   
    Polygon<int> testPoly;

	Point<int> p0(0, -2);
	testPoly.addPoint(p0);

	Point<int> p1(6, -2);
	testPoly.addPoint(p1);

	Point<int> p2(9, -0);
	testPoly.addPoint(p2);

	Point<int> p3(6, 2);
	testPoly.addPoint(p3);

	Point<int> p4(9, 4);
	testPoly.addPoint(p4);

	Point<int> p5(4, 7);
	testPoly.addPoint(p5);

	Point<int> p6(-1, 6);
	testPoly.addPoint(p6);

	Point<int> p7(-3, 3);
	testPoly.addPoint(p7);

    EXPECT_EQ(testPoly.getArea2(), 153);
    EXPECT_TRUE(fabs(testPoly.getArea() - 76.5f) < 1E-5);
}

TEST(intPolygon, CCWTest1)
{   
    Polygon<int> testPoly;

	Point<int> p0(0, 0);
	testPoly.addPoint(p0);

	Point<int> p1(50, 0);
	testPoly.addPoint(p1);

	Point<int> p2(50, 20);
	testPoly.addPoint(p2);

	Point<int> p3(0, 20);
	testPoly.addPoint(p3);

	EXPECT_TRUE(testPoly.isCCW());
}

TEST(intPolygon, CCWTest2)
{   
    Polygon<int> testPoly;

    Point<int> p0(-10, -10);
	testPoly.addPoint(p0);

	Point<int> p2(0, 10);
	testPoly.addPoint(p2);

	Point<int> p1(10, -10);
	testPoly.addPoint(p1);

	EXPECT_FALSE(testPoly.isCCW());
}

TEST(intPolygon, CCWTest3)
{   
    Polygon<int> testPoly;

	Point<int> p0(0, -2);
	testPoly.addPoint(p0);

	Point<int> p1(6, -2);
	testPoly.addPoint(p1);

	Point<int> p2(9, -0);
	testPoly.addPoint(p2);

	Point<int> p3(6, 2);
	testPoly.addPoint(p3);

	Point<int> p4(9, 4);
	testPoly.addPoint(p4);

	Point<int> p5(4, 7);
	testPoly.addPoint(p5);

	Point<int> p6(-1, 6);
	testPoly.addPoint(p6);

	Point<int> p7(-3, 3);
	testPoly.addPoint(p7);

	EXPECT_TRUE(testPoly.isCCW());
}

TEST(intPolygon, BorderTest)
{   
    Polygon<int> testPoly;

    Point<int> p0(3, -1);
	testPoly.addPoint(p0);

	Point<int> p2(0, 2);
	testPoly.addPoint(p2);

	Point<int> p1(-2, -1);
	testPoly.addPoint(p1);

    Point<int> q1(1, -1);
    Point<int> q2(0, 0);
    Point<int> q3(0, -3);

    EXPECT_TRUE(testPoly.isInBorder(q1));
    EXPECT_FALSE(testPoly.isInBorder(q2));
    EXPECT_FALSE(testPoly.isInBorder(q3));
}

TEST(intPolygon, InsideTest1)
{   
    Polygon<int> testPoly;

	Point<int> p0(1, 5);
	testPoly.addPoint(p0);

	Point<int> p1(0, 2);
	testPoly.addPoint(p1);

	Point<int> p2(2, 0);
	testPoly.addPoint(p2);

	Point<int> p3(4, 1);
	testPoly.addPoint(p3);

	Point<int> p4(5, 3);
	testPoly.addPoint(p4);

    Point<int> q1(2, 3);
    Point<int> q2(1, 5);
    Point<int> q3(3, 4);

    Point<int> r1(-1, 4);
    Point<int> r2(6, 1);

    EXPECT_TRUE(testPoly.isInside(q1));
    EXPECT_TRUE(testPoly.isInside(q2));
    EXPECT_TRUE(testPoly.isInside(q3));

    EXPECT_FALSE(testPoly.isInside(r1));
    EXPECT_FALSE(testPoly.isInside(r2));
}

TEST(intPolygon, InsideTest2)
{   
    Polygon<int> testPoly;

	Point<int> p0(-2, 0);
	testPoly.addPoint(p0);

	Point<int> p1(-4, -3);
	testPoly.addPoint(p1);

	Point<int> p2(-2, -6);
	testPoly.addPoint(p2);

	Point<int> p3(2, -3);
	testPoly.addPoint(p3);

	Point<int> p4(-1, -3);
	testPoly.addPoint(p4);

    Point<int> q1(-2, -3);
    Point<int> q2(1, -3);

    Point<int> r1(-5, 3);
    Point<int> r2(0, -2);

    EXPECT_TRUE(testPoly.isInside(q1));
    EXPECT_TRUE(testPoly.isInside(q2));

    EXPECT_FALSE(testPoly.isInside(r1));
    EXPECT_FALSE(testPoly.isInside(r2));
}

TEST(intPolygon, InsideTest3)
{   
    Polygon<int> testPoly;

	Point<int> p0(-4, 5);
	testPoly.addPoint(p0);

	Point<int> p1(-5, 1);
	testPoly.addPoint(p1);

	Point<int> p2(0, -2);
	testPoly.addPoint(p2);

	Point<int> p3(4, 2);
	testPoly.addPoint(p3);

	Point<int> p4(3, 5);
	testPoly.addPoint(p4);

	testPoly.addPoint(Point<int>(-1,2));

    Point<int> q1(-4, 3);
    Point<int> q2(2, 3);
    Point<int> q3(0, -1);

    Point<int> r1(-5, 4);
    Point<int> r2(-1, 4);
    Point<int> r3(4, 4);

    EXPECT_TRUE(testPoly.isInside(q1));
    EXPECT_TRUE(testPoly.isInside(q2));
    EXPECT_TRUE(testPoly.isInside(q3));

    EXPECT_FALSE(testPoly.isInside(r1));
    EXPECT_FALSE(testPoly.isInside(r2));
    EXPECT_FALSE(testPoly.isInside(r3));
}

TEST(intPolygon, EqualTest1)
{   
    Polygon<int> poly1;
	poly1.addPoint(Point<int>(-4, 5));
	poly1.addPoint(Point<int>(-5, 1));
	poly1.addPoint(Point<int>( 0,-2));
	poly1.addPoint(Point<int>( 4, 2));
	poly1.addPoint(Point<int>( 3, 5));
	poly1.addPoint(Point<int>(-1, 2));

	Polygon<int> poly2;
	poly2.addPoint(Point<int>(-4, 5));
	poly2.addPoint(Point<int>(-5, 1));
	poly2.addPoint(Point<int>( 0,-2));
	poly2.addPoint(Point<int>( 4, 2));
	poly2.addPoint(Point<int>( 3, 5));
	poly2.addPoint(Point<int>(-1, 2));

    EXPECT_TRUE(poly1 == poly2);
}

TEST(intPolygon, EqualTest2)
{   
    Polygon<int> poly1;
	poly1.addPoint(Point<int>(-4, 5));
	poly1.addPoint(Point<int>(-5, 1));
	poly1.addPoint(Point<int>( 0,-2));
	poly1.addPoint(Point<int>( 4, 2));
	poly1.addPoint(Point<int>( 3, 5));
	poly1.addPoint(Point<int>(-1, 2));

	Polygon<int> poly2;
	poly2.addPoint(Point<int>( 4, 2));
	poly2.addPoint(Point<int>( 3, 5));
	poly2.addPoint(Point<int>(-1, 2));
	poly2.addPoint(Point<int>(-4, 5));
	poly2.addPoint(Point<int>(-5, 1));
	poly2.addPoint(Point<int>( 0,-2));

    EXPECT_TRUE(poly1 == poly2);
}

TEST(intPolygon, NotEqualTest1)
{   
    Polygon<int> poly1;
	poly1.addPoint(Point<int>(-4, 5));
	poly1.addPoint(Point<int>(-5, 1));
	poly1.addPoint(Point<int>( 0,-2));
	poly1.addPoint(Point<int>( 4, 2));
	poly1.addPoint(Point<int>( 3, 5));
	poly1.addPoint(Point<int>(-1, 2));

	Polygon<int> poly2;
	poly2.addPoint(Point<int>( 4, 2));
	poly2.addPoint(Point<int>( 3, 5));
	poly2.addPoint(Point<int>(-1, 2));
	poly2.addPoint(Point<int>(-4, 5));

    EXPECT_FALSE(poly1 == poly2);
}

TEST(intPolygon, NotEqualTest2)
{   
    Polygon<int> poly1;
	poly1.addPoint(Point<int>(-4, 5));
	poly1.addPoint(Point<int>(-5, 1));
	poly1.addPoint(Point<int>( 0,-2));
	poly1.addPoint(Point<int>( 4, 2));
	poly1.addPoint(Point<int>( 3, 5));
	poly1.addPoint(Point<int>(-1, 2));

	Polygon<int> poly2;
	poly2.addPoint(Point<int>( 4, 2));
	poly2.addPoint(Point<int>( 3, 5));
	poly2.addPoint(Point<int>(-1, 2));
	poly2.addPoint(Point<int>(-4, 5));
	poly2.addPoint(Point<int>( 0,-2));
	poly2.addPoint(Point<int>(-5, 1));

    EXPECT_FALSE(poly1 == poly2);
}