#pragma once
#include "point.hpp"

template<class T>
class Segment
{
    public:
        Segment();
        Segment(Point<T>& fromPoint, Point<T>& toPoint);
        Segment(T originX, T originY, T endX, T endY);
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
    this->mOrigin = new Point<int>(0, 0);
    this->mEnd = new Point<int>(0, 0);
}

template<class T>
Segment<T>::Segment(T originX, T originY, T endX, T endY)
{
    this->mOrigin = new Point<int>(originX, originY);
    this->mEnd = new Point<int>(endX, endY);
}