#include <octagram/polygon.hpp>

void Polygon::addPoint(Point<int>& point)
{
	points.push_back(point);
}

int Polygon::getSize()
{
    return this->points.size();
}