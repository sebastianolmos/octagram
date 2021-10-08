#pragma once
#include "point.hpp"
#include <vector>
using namespace std;

class Polygon
{
    public:
        void addPoint(Point<int>& point);
        int getSize();
    private:
        vector<Point<int>> points;
};