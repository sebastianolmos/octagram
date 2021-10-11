#pragma once
#include<iostream>
#include<string> 
#include <math.h> 
#include "point.hpp"
#include "vector.hpp"
using std::ostream;

template<class T>
class Segment;

template<class T>
ostream& operator<< (ostream& os, const Segment<T>& segment);
template<class T>
bool operator==(const Segment<T>& seg1, const Segment<T>& seg2);

template<class T>
class Segment
{
    public:
        Segment();
        Segment(Point<T>& fromPoint, Point<T>& toPoint);
        Segment(T originX, T originY, T endX, T endY);
        ~Segment();
        Point<T> getOrigin();
        Point<T> getEnd();
        void setOrigin(Point<T>& point);
        void setEnd(Point<T>& point);
        friend ostream& operator<< <>(ostream& os, const Segment& segment);
        friend bool operator==<T>(const Segment& seg1, const Segment& seg2);
        T getLength2();
        float getLength();
        bool left(const Point<T>& point);
        bool right(const Point<T>& point);
        bool colinear(const Point<T>& point);
    private:
        Point<T>* mOrigin;
        Point<T>* mEnd;
};

template<class T>
Segment<T>::Segment()
{
    this->mOrigin = new Point<T>(0, 0);
    this->mEnd = new Point<T>(0, 0);
}

template<class T>
Segment<T>::Segment(Point<T>& fromPoint, Point<T>& toPoint)
{
    this->mOrigin = new Point<int>(fromPoint);
    this->mEnd = new Point<int>(toPoint);
}

template<class T>
Segment<T>::Segment(T originX, T originY, T endX, T endY)
{
    this->mOrigin = new Point<int>(originX, originY);
    this->mEnd = new Point<int>(endX, endY);
}

template<class T>
Segment<T>::~Segment()
{
    delete this->mOrigin;
    delete this->mEnd;
}

template<class T>
Point<T> Segment<T>::getOrigin()
{
    return *mOrigin;
}

template<class T>
Point<T> Segment<T>::getEnd()
{
    return *mEnd;
}

template<class T>
void Segment<T>::setOrigin(Point<T>& point)
{
    *mOrigin = point;
}

template<class T>
void Segment<T>::setEnd(Point<T>& point)
{
    *mEnd = point;
}

template<class T>
ostream& operator<<(ostream& os, const Segment<T>& segment)
{
	os << "S(From " << *(segment.mOrigin) << " to " << *(segment.mEnd) << ")";
	return os;
}

template<class T>
bool operator==(const Segment<T>& seg1, const Segment<T>& seg2)
{
    return (*(seg1.mOrigin) == *(seg2.mOrigin)) && (*(seg1.mEnd) == *(seg2.mEnd));
}

template<class T>
T Segment<T>::getLength2()
{
    T prodX = mOrigin->getX() -  mEnd->getX();
    T prodY = mOrigin->getY() -  mEnd->getY();
    return prodX * prodX + prodY * prodY;
}

template<class T>
float Segment<T>::getLength()
{
    return sqrt(this->getLength2());
}

template<class T>
bool Segment<T>::left(const Point<T>& point)
{
    Vector<T> vec1(*mOrigin, *mEnd);
    Point<T> cPoint = point;
    Vector<T> vec2(*mOrigin, cPoint);
    Vector<T> vecArea = vec1.cross(vec2);
    T area2 = vecArea.getZ();
    return area2 > 0;
}

template<class T>
bool Segment<T>::right(const Point<T>& point)
{
    Vector<T> vec1(*mOrigin, *mEnd);
    Point<T> cPoint = point;
    Vector<T> vec2(*mOrigin, cPoint);
    Vector<T> vecArea = vec1.cross(vec2);
    T area2 = vecArea.getZ();
    return area2 < 0;
}

template<class T>
bool Segment<T>::colinear(const Point<T>& point)
{
    Vector<T> vec1(*mOrigin, *mEnd);
    Point<T> cPoint = point;
    Vector<T> vec2(*mOrigin, cPoint);
    Vector<T> vecArea = vec1.cross(vec2);
    T area2 = vecArea.getZ();
    if (area2 == 0 ){
        return true;
    } 
    else {
        return fabs(area2) < 1E-6;
    }
}

