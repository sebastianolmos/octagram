#include <gtest/gtest.h>
#include "octagram/point.hpp"
#include "octagram/polygon.hpp"
#include "octagram/algorithm/convexhull.hpp"

TEST(intConvexHull, giftWrappingBasicTest)
{   
    Point<int> testPoints[] = {Point<int>( 4, 2), Point<int>( 1, -3)};
    Polygon<int> testPoly = giftWrapping<int>(testPoints, 2);
    EXPECT_TRUE(testPoly.getCount() == 0);
}

TEST(intConvexHull, giftWrappingTest1)
{   
    Point<int> testPoints[] = {
        Point<int>( 2, 2), Point<int>( 8, 2),  Point<int>( 3, 5),
        Point<int>( 7, 4), Point<int>( 9, 4),  Point<int>( 11, 5),
        Point<int>( 6, 6), Point<int>( 10, 8),  Point<int>( 3, 9),
        Point<int>( 6, 11), Point<int>( 10, 11),  Point<int>( 13, 11),
        Point<int>( 2, 12), Point<int>( 8, 13),  Point<int>( 11, 13)
        };

    Polygon<int> expectedPoly;
    expectedPoly.addPoint(2, 2);
    expectedPoly.addPoint( 8, 2);
    expectedPoly.addPoint( 11, 5);
    expectedPoly.addPoint( 13, 11);
    expectedPoly.addPoint( 11, 13);
    expectedPoly.addPoint( 8, 13);
    expectedPoly.addPoint( 2, 12);

    Polygon<int> resultPoly = giftWrapping<int>(testPoints, 15);
    EXPECT_EQ(resultPoly.getCount(), 7);
    EXPECT_TRUE(expectedPoly == resultPoly);
}

TEST(intConvexHull, giftWrappingSortTest)
{   
    Point<int> testPoints1[] = {
        Point<int>( 2, 2), Point<int>( 8, 2),  Point<int>( 3, 5),
        Point<int>( 7, 4), Point<int>( 9, 4),  Point<int>( 11, 5),
        Point<int>( 6, 6), Point<int>( 10, 8),  Point<int>( 3, 9),
        Point<int>( 6, 11), Point<int>( 10, 11),  Point<int>( 13, 11),
        Point<int>( 2, 12), Point<int>( 8, 13),  Point<int>( 11, 13)
        };

    Point<int> testPoints2[] = {
        Point<int>( 9, 4), Point<int>( 10, 8),  Point<int>( 3, 9),
        Point<int>( 2, 2), Point<int>( 8, 2),  Point<int>( 6, 11),
        Point<int>( 3, 5), Point<int>( 10, 11),  Point<int>( 13, 11),
        Point<int>( 7, 4), Point<int>( 6, 6),  Point<int>( 11, 5),
        Point<int>( 2, 12), Point<int>( 8, 13),  Point<int>( 11, 13)
        };

    Polygon<int> resultPoly1 = giftWrapping<int>(testPoints1, 15);
    Polygon<int> resultPoly2 = giftWrapping<int>(testPoints2, 15);

    EXPECT_TRUE(resultPoly1 == resultPoly2);
}

TEST(intConvexHull, grahamScanBasicTest)
{   
    Point<int> testPoints[] = {Point<int>( 4, 2), Point<int>( 1, -3)};
    Polygon<int> testPoly = grahamScan<int>(testPoints, 2);
    EXPECT_TRUE(testPoly.getCount() == 0);
}

TEST(intConvexHull, grahamScanTest1)
{   
    Point<int> testPoints[] = {
        Point<int>( 2, 2), Point<int>( 8, 2),  Point<int>( 3, 5),
        Point<int>( 7, 4), Point<int>( 9, 4),  Point<int>( 11, 5),
        Point<int>( 6, 6), Point<int>( 10, 8),  Point<int>( 3, 9),
        Point<int>( 6, 11), Point<int>( 10, 11),  Point<int>( 13, 11),
        Point<int>( 2, 12), Point<int>( 8, 13),  Point<int>( 11, 13)
        };

    Polygon<int> expectedPoly;
    expectedPoly.addPoint( 2, 2);
    expectedPoly.addPoint( 8, 2);
    expectedPoly.addPoint( 11, 5);
    expectedPoly.addPoint( 13, 11);
    expectedPoly.addPoint(11, 13);
    expectedPoly.addPoint( 8, 13);
    expectedPoly.addPoint( 2, 12);

    Polygon<int> resultPoly = grahamScan<int>(testPoints, 15);
    EXPECT_EQ(resultPoly.getCount(), 7);
    EXPECT_TRUE(expectedPoly == resultPoly);
}

TEST(intConvexHull, grahamScanSortTest)
{   
    Point<int> testPoints1[] = {
        Point<int>( 2, 2), Point<int>( 8, 2),  Point<int>( 3, 5),
        Point<int>( 7, 4), Point<int>( 9, 4),  Point<int>( 11, 5),
        Point<int>( 6, 6), Point<int>( 10, 8),  Point<int>( 3, 9),
        Point<int>( 6, 11), Point<int>( 10, 11),  Point<int>( 13, 11),
        Point<int>( 2, 12), Point<int>( 8, 13),  Point<int>( 11, 13)
        };

    Point<int> testPoints2[] = {
        Point<int>( 9, 4), Point<int>( 10, 8),  Point<int>( 3, 9),
        Point<int>( 2, 2), Point<int>( 8, 2),  Point<int>( 6, 11),
        Point<int>( 3, 5), Point<int>( 10, 11),  Point<int>( 13, 11),
        Point<int>( 7, 4), Point<int>( 6, 6),  Point<int>( 11, 5),
        Point<int>( 2, 12), Point<int>( 8, 13),  Point<int>( 11, 13)
        };

    Polygon<int> resultPoly1 = grahamScan<int>(testPoints1, 15);
    Polygon<int> resultPoly2 = grahamScan<int>(testPoints2, 15);

    EXPECT_TRUE(resultPoly1 == resultPoly2);
}

