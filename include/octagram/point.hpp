#pragma once
#include<iostream>
#include<string> 
#include <math.h> 
using std::ostream;

template<class T>
class Point;

template<class T>
ostream& operator<< (ostream& os, const Point<T>& point);
template<class T>
bool operator==(const Point<T>& point1, const Point<T>& point2);

template<class T>
class Point
{
    public:
        Point();
        Point(T x, T y);
        Point(const Point<T>& point);
        ~Point();
        T getX();
        T getY();
        friend ostream& operator<< <>(ostream& os, const Point& point);
	    friend bool operator==<T>(const Point& point1, const Point& point2);
        const Point<T> operator+ (const Point<T>&)const;
	    const Point<T> operator- (const Point<T>&)const;
        const Point<T> operator* (const T)const;
    private:
        T mX;
        T mY;
        double EPSILON = 1E-6;
};

template<class T>
Point<T>::Point()
{
    this->mX = 0;
    this->mY = 0;
}

template<class T>
Point<T>::Point(T x, T y)
{
    this->mX = x;
    this->mY = y;
}

template<class T>
Point<T>::Point(const Point<T>& point)
{	
	this->mX = point.mX;
    this->mY = point.mY;
}

template<class T>
Point<T>::~Point()
{
	this->mX = 0;
    this->mY = 0;
}

template<class T>
T Point<T>::getX()
{
	return mX;
}

template<class T>
T Point<T>::getY()
{
	return mY;
}

template<class T>
ostream& operator<<(ostream& os, const Point<T>& point)
{
	os << "P(" << point.mX << ", " << point.mY <<  ")";
	return os;
}

template<class T>
bool operator==(const Point<T>& point1, const Point<T>& point2)
{
    if (point1.mX == point2.mX && point1.mY == point2.mY){
        return true;
    }
    else {
        bool equalInX = fabs(point1.mX - point2.mX) <= ( (fabs(point1.mX) < fabs(point2.mX) ? fabs(point2.mX) : fabs(point1.mX)) * point1.EPSILON);
	    bool equalInY = fabs(point1.mY - point2.mY) <= ( (fabs(point1.mY) < fabs(point2.mY) ? fabs(point2.mY) : fabs(point1.mY)) * point1.EPSILON);
        return equalInX && equalInY;
    }
}

template<class T>
const Point<T> Point<T>::operator+(const Point<T>& point) const
{
	return { this->mX + point.mX, this->mY + point.mY};
}

template<class T>
const Point<T> Point<T>::operator-(const Point<T>& point) const
{
	return { this->mX - point.mX, this->mY - point.mY};
}

template<class T>
const Point<T> Point<T>::operator*(const T scale) const
{
	return { this->mX * scale, this->mY * scale};
}