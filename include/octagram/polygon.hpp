#pragma once
#include<iostream>
#include<string> 
#include <math.h> 
#include "point.hpp"
#include "vector.hpp"
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
        void addPoint(Point<T>& point);
        T getArea2();
        float getArea();
        int getCount();
        bool isCCW();
        bool isInside(Point<T>& point);
        friend ostream& operator<< <>(ostream& os, const Polygon<T>& polygon);
    private:
        vector<Point<T>> points;
};