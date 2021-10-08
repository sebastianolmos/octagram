#pragma once
#include<iostream>
#include<string> 
#include <math.h> 
#include "point.hpp"
using std::ostream;

template<class T>
class Vector;

template<class T>
ostream& operator<< (ostream& os, const Vector<T>& vector);
template<class T>
bool operator==(const Vector<T>& vec1, const Vector<T>& vec2);

template<class T>
class Vector
{
    public:
        Vector();
        Vector(T x, T y, T z);
        Vector(const Vector<T>& vector);
	    Vector(Point<T>& fromPoint, Point<T>& toPoint);
        ~Vector();
        T getX();
        T getY();
        T getZ();
        friend ostream& operator<< <>(ostream& os, const Vector& vector);
        friend bool operator==<T>(const Vector& vec1, const Vector& vec2);
        const Vector<T> operator+ (const Vector<T>&)const;
        const Vector<T> operator- (const Vector<T>&)const;
        const Vector<T> operator* (const T)const;
        const T dot(const Vector<T>& vector);
        const Vector<T> cross(const Vector<T>& vector);
        T getMagnitude2();
        float getMagnitude();
        void normalize();
        void set(T x, T y, T z);
    private:
        T mX;
        T mY;
        T mZ;
        double EPSILON = 1E-6;
};

template<class T>
Vector<T>::Vector()
{
    this->mX = 0;
    this->mY = 0;
    this->mZ = 0;
}

template<class T>
Vector<T>::Vector(T x, T y, T z)
{
    this->mX = x;
    this->mY = y;
    this->mZ = z;
}

template<class T>
Vector<T>::Vector(const Vector<T>& vector)
{	
	this->mX = vector.mX;
    this->mY = vector.mY;
    this->mZ = vector.mZ;
}

template<class T>
Vector<T>::Vector(Point<T>& fromPoint, Point<T>& toPoint)
{
    this->mX = (toPoint.getX() - fromPoint.getX());
    this->mY = (toPoint.getY() - fromPoint.getY());
    this->mZ = 0;
}

template<class T>
Vector<T>::~Vector()
{
	this->mX = 0;
    this->mY = 0;
    this->mZ = 0;
}


template<class T>
T Vector<T>::getX()
{
	return mX;
}

template<class T>
T Vector<T>::getY()
{
	return mY;
}

template<class T>
T Vector<T>::getZ()
{
	return mZ;
}

template<class T>
ostream& operator<<(ostream& os, const Vector<T>& vector)
{
	os << "V(" << vector.mX << ", " << vector.mY << ", " << vector.mZ << ")";
	return os;
}

template<class T>
bool operator==(const Vector<T>& vec1, const Vector<T>& vec2)
{
    if (vec1.mX == vec2.mX && vec1.mY == vec2.mY && vec1.mZ == vec2.mZ){
        return true;
    }
    else {
        bool equalInX = fabs(vec1.mX - vec2.mX) <= ( (fabs(vec1.mX) < fabs(vec2.mX) ? fabs(vec2.mX) : fabs(vec1.mX)) * vec1.EPSILON);
	    bool equalInY = fabs(vec1.mY - vec2.mY) <= ( (fabs(vec1.mY) < fabs(vec2.mY) ? fabs(vec2.mY) : fabs(vec1.mY)) * vec1.EPSILON);
        bool equalInZ = fabs(vec1.mZ - vec2.mZ) <= ( (fabs(vec1.mZ) < fabs(vec2.mZ) ? fabs(vec2.mZ) : fabs(vec1.mZ)) * vec1.EPSILON);
        return equalInX && equalInY && equalInZ;
    }
}

template<class T>
const Vector<T> Vector<T>::operator+(const Vector<T>& vector) const
{
	return {this->mX + vector.mX, this->mY + vector.mY, this->mZ + vector.mZ};
}

template<class T>
const Vector<T> Vector<T>::operator-(const Vector<T>& vector) const
{
	return {this->mX - vector.mX, this->mY - vector.mY, this->mZ - vector.mZ};
}

template<class T>
const Vector<T> Vector<T>::operator*(const T scale) const
{
	// std::cout << " hallo!" << std::endl;
	return { this->mX * scale, this->mY * scale, this->mZ * scale };
}

template<class T>
const T Vector<T>::dot(const Vector<T>& vector) 
{
	return (this->mX * vector.mX) + (this->mY * vector.mY) + (this->mZ * vector.mZ);
}

template<class T>
const Vector<T> Vector<T>::cross(const Vector<T>& vector)
{
	return { this->mY * vector.mZ - this->mZ * vector.mY,
			this->mZ * vector.mX - this->mX * vector.mZ,
			this->mX * vector.mY - this->mY * vector.mX};
}

template<class T>
T Vector<T>::getMagnitude2()
{
	return (this->mX * this->mX) + (this->mY * this->mY) + (this->mZ * this->mZ);
}

template<class T>
float Vector<T>::getMagnitude()
{
	return sqrt(this->getMagnitude2());
}

template<class T>
void Vector<T>::normalize()
{
	T magnitude = (T)(this->getMagnitude());
	
	this->mX = (this->mX / magnitude);
	this->mY = (this->mY / magnitude);
	this->mZ = (this->mZ / magnitude);
}

template<>
void Vector<int>::normalize()
{
    if (fabs(this->mX) > fabs(this->mY) && fabs(this->mX) > fabs(this->mZ)){
        int sgn = (this->mX > 0) ? 1 : ((this->mX < 0) ? -1 : 0);
        this->mX = sgn;
        this->mY = 0;
        this->mZ = 0;
    }
    else if (fabs(this->mY) > fabs(this->mX) && fabs(this->mY) > fabs(this->mZ)){
        int sgn = (this->mY > 0) ? 1 : ((this->mY < 0) ? -1 : 0);
        this->mX = 0;
        this->mY = sgn;
        this->mZ = 0;
    }
    else if (fabs(this->mZ) > fabs(this->mX) && fabs(this->mZ) > fabs(this->mY)){
        int sgn = (this->mZ > 0) ? 1 : ((this->mZ < 0) ? -1 : 0);
        this->mX = 0;
        this->mY = 0;
        this->mZ = sgn;
    }
    else {
        this->mX = 0;
        this->mY = 0;
        this->mZ = 0;
    }
}

template<class T>
void Vector<T>::set(T x, T y, T z)
{
	this->mX = x;
	this->mY = y;
	this->mZ = z;
}