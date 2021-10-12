#pragma once
#include<iostream>
#include<string> 
#include <math.h> 
#include "point.hpp"
#include "vector.hpp"
#include "segment.hpp"
using std::ostream;
#include <vector>
using namespace std;

template<class T>
class Polygon;

template<class T>
ostream& operator<< (ostream& os, const Polygon<T>& polygon);

template<class T>
class Polygon
{
    public:
        Polygon(Point<T>& point);
        ~Polygon();
        void addPoint(Point<T>& point);
        friend ostream& operator<< <>(ostream& os, const Polygon<T>& polygon);
        T getArea2();
        float getArea();
        int getCount();
        bool isCCW();
        bool isInBorder(Point<T>& point);
        bool isInside(Point<T>& point);
    private:
        vector<Point<T>> points;
};

template<class T>
Polygon<T>::Polygon(Point<T>& point)
{
	points.push_back(point);
}

template<class T>
Polygon<T>::~Polygon()
{
	points.clear();
}

template<class T>
void Polygon<T>::addPoint(Point<T>& point)
{
	points.push_back(point);
}

template<class T>
ostream& operator<<(ostream& os, const Polygon<T>& polygon)
{
	os << "Polygon(";
	for (int i = 0; i < (polygon.points.size()); i++)
	{

		os << polygon.points[i];
		if (i < (polygon.points.size() - 1)) {
			os << ", ";
		}
	}
	os << ")";
	return os;
}

template<class T>
T Polygon<T>::getArea2()
{
	T sum = 0;
    for (int i = 1; i < (points.size() - 1); i++){
        Vector<T> vecA1(points[0], points[i]);
		Vector<T> vecA2(points[0], points[i + 1]);
		Vector<T> vecCross = vecA1.cross(vecA2);
        sum += vecCross.getZ();
    }
    return sum;
}

template<class T>
float Polygon<T>::getArea()
{
	T area2 = getArea2();
    return area2 * 0.5f;
}

template<class T>
int Polygon<T>::getCount()
{
	return points.size()
}

template<class T>
bool Polygon<T>::isCCW()
{
	T area2 = getArea2();
    return area2 > 0;
}

template<class T>
bool Polygon<T>::isInBorder(Point<T>& point)
{
    for (int i = 0; i < points.size(); i++){
		Segment<T> seg(points[i], points[(i + 1]) % points.size());
		if (seg.colinear(point)) {
            return true;
        }
    }
    return false;
}

template<class T>
bool Polygon<T>::isInside(Point<T>& point)
{
    if (isInBorder(point)){
        return true;
    }

    int Rcross = 0;
    T axis = point.getY();
    for (int i = 0; i < points.size(); i++){
		Segment<T> seg(points[i], points[(i + 1]) % points.size());
		if (seg.checkIntersection(axis)) {
            double x = seg.getIntersection(axis);

            if (x > point.getX()){
                Rcross++;
            }
        }
    }
    if ((Rcross % 2) == 1) {
        return true;
    } 
    else {
        return false;
    }
}