#include <gtest/gtest.h>
#include "octagram/point.hpp"
#include "octagram/polygon.hpp"
#include "octagram/algorithm/convexhull.hpp"
#include "octagram/sampling/generation.hpp"

TEST(generation, giftWrappingGenTest1)
{   
    Point<double>* testPoints = createHullPoints(100, 0.5, 1000.0);
    Polygon<double> gfHull = giftWrapping(testPoints, 100);
    int count = 0;
    for (int i = 0; i < 100; i++){
        if (gfHull.isInBorder(testPoints[i])){
            count++;
        }
    }
    EXPECT_EQ(gfHull.getCount(), 50);
    EXPECT_EQ(count, 50);
}

TEST(generation, grahamScanGenTest1)
{   
    Point<double>* testPoints = createHullPoints(100, 0.6, 1000.0);
    Polygon<double> gsHull = grahamScan(testPoints, 100);
    int count = 0;
    for (int i = 0; i < 100; i++){
        if (gsHull.isInBorder(testPoints[i])){
            count++;
        }
    }
    EXPECT_EQ(gsHull.getCount(), 60);
    EXPECT_EQ(count, 60);
}