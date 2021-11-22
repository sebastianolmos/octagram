#include <gtest/gtest.h>
#include "octagram/algorithm/convexhull.hpp"
#include <cmath>

#include <limits>
# define M_PI           3.14159265358979323846  /* pi */

TEST(algTest, iniTest)
{   
    std::setprecision(std::numeric_limits<long double>::digits10 + 1);
    double angle = std::acos(-1.L) /100.0;
    std::cout << "--------> 100 <--------" << std::endl;
    std::cout << angle<< std::endl;
    std::cout << std::sin(angle) << " " << std::cos(angle) << std::endl;
    std::cout << (float)std::sin(angle) << " " << (float)std::cos(angle) << std::endl;
    std::cout  << (double)std::sin(angle) << " " << (double)std::cos(angle) << std::endl;
    std::cout << (long double)std::sin(angle) << " " << (long double)std::cos(angle) << std::endl;

    angle = M_PI /1000.0;
    std::cout << "--------> 100 <--------" << std::endl;
    std::cout << angle<< std::endl;
    std::cout << std::sin(angle) << " " << std::cos(angle) << std::endl;
    std::cout << (float)std::sin(angle) << " " << (float)std::cos(angle) << std::endl;
    std::cout << (double)std::sin(angle) << " " << (double)std::cos(angle) << std::endl;
    std::cout << (long double)std::sin(angle) << " " << (long double)std::cos(angle) << std::endl;

    angle = M_PI /10000.0;
    std::cout << "--------> 100 <--------" << std::endl;
    std::cout << angle<< std::endl;
    std::cout << std::sin(angle) << " " << std::cos(angle) << std::endl;
    std::cout << (float)std::sin(angle) << " " << (float)std::cos(angle) << std::endl;
    std::cout << (double)std::sin(angle) << " " << (double)std::cos(angle) << std::endl;
    std::cout << (long double)std::sin(angle) << " " << (long double)std::cos(angle) << std::endl;

    angle = M_PI /100000.0;
    std::cout << "--------> 100 <--------" << std::endl;
    std::cout << angle<< std::endl;
    std::cout << std::sin(angle) << " " << std::cos(angle) << std::endl;
    std::cout << (float)std::sin(angle) << " " << (float)std::cos(angle) << std::endl;
    std::cout << (double)std::sin(angle) << " " << (double)std::cos(angle) << std::endl;
    std::cout << (long double)std::sin(angle) << " " << (long double)std::cos(angle) << std::endl;

    angle = M_PI /1000000.0;
    std::cout << "--------> 100 <--------" << std::endl;
    std::cout << angle<< std::endl;
    std::cout << std::sin(angle) << " " << std::cos(angle) << std::endl;
    std::cout << (float)std::sin(angle) << " " << (float)std::cos(angle) << std::endl;
    std::cout << (double)std::sin(angle) << " " << (double)std::cos(angle) << std::endl;
    std::cout << std::sin(angle) << " " << std::cos(angle) << std::endl;
    //std::cout << std::sin(angle) << " " << std::cos(angle) << std::endl;
    float tt = testsum2<float>(2.0, 4.0);
    EXPECT_TRUE(tt > 5.0);
}