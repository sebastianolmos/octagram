#include <stack>
#include <vector>
#include <stdlib.h>
#include "octagram/point.hpp"
#include "octagram/segment.hpp"
#include "octagram/polygon.hpp"

using namespace std;

template <class T>
T testsum2(T a, T b){
    Point<int>* testPoint = new Point<int>();
    delete testPoint;
    return a + b;
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
template <class T>
int orientation(Point<T> p, Point<T> q, Point<T> r){
    T val = (q.getY() - p.getY()) * (r.getX() - q.getX())  -
            (q.getX() - p.getX()) * (r.getY() - q.getY());

    if (val == 0) return 0;
    return (val > (T)0)? 1:2;
}

template <class T>
Polygon<T> giftWrapping(Point<T> points[], int n){
    Polygon<T> hull;
    if (n < 3) {
        return hull;
    }
    int l = 0;
    for (int i = 1; i < n; i++){
        if (points[i].getX() < points[l].getX()){
            l = i;
        }
    }
    int p = l;
    int q;
    do {
        hull.addPoint(points[p]);
        q = (p + 1)%n;
        for (int i = 0; i < n; i++){
            if (orientation<T>(points[p], points[i], points[q]) == 2){
                q = i;
            }
        }
        p = q;
    } while (p != l);
    return hull;
}

template <class T>
Point<T> p0;

// A utility function to find next to top in a stack
template <class T>
Point<T> nextToTop(vector<Point<T>> &S){
    Point<T> p = S.back();
    S.pop_back();
    Point<T> res = S.back();
    S.push_back(p);
    return res;
}

// A utility function to swap two points
template <class T>
void swap(Point<T> &p1, Point<T> &p2){
    Point<T> temp = p1;
    p1 = p2;
    p2 = temp;
}

// A utility function to return square of distance between p1 and p2
template <class T>
T distSq(Point<T> p1, Point<T> p2){
    return (p1.getX() - p2.getX())*(p1.getX() - p2.getX()) +
        (p1.getY() - p2.getY())*(p1.getY() - p2.getY());
}

// A function used by library function qsort() to sort an array of
// points with respect to the first point
template <class T>
int compare(const void *vp1, const void *vp2)
{
   Point<T> *p1 = (Point<T> *)vp1;
   Point<T> *p2 = (Point<T> *)vp2;
 
   // Find orientation
   int o = orientation<T>(p0<T>, *p1, *p2);
   if (o == 0)
     return (distSq<T>(p0<T>, *p2) >= distSq<T>(p0<T>, *p1))? -1 : 1;
 
   return (o == 2)? -1: 1;
}

template <class T>
Polygon<T> grahamScan(Point<T> points[], int n){
    // Find the bottommost point
    T ymin = points[0].getY();
    int min = 0;
    for (int i = 1; i < n; i++){
        T y = points[i].getY();
        // Pick the bottom-most or chose the left most point in case of tie
        if ( (y < ymin) || (ymin == y && points[i].getX()<points[min].getX()) ){
            ymin = points[i].getY();
            min = i;
        }
    }
    swap<T>(points[0], points[min]); // Place the bottom-most point at first position

    // Sort n-1 points with respect to the first point.
    // A point p1 comes before p2 in sorted output if p2 has larger polar angle (in ccw) than p1
    p0<T> = points[0];
    qsort(&points[1], n-1, sizeof(Point<T>), compare<T>);
    
    // If two or more points make same angle with p0, remove all but the one that is farthest from p0
    int m = 1; // Initialize size of modified array
    for (int i = 1; i < n; i++){
        // Keep removing i while angle of i and i+1 is same with respect to p0
        while (i < n-1 && orientation<T>(p0<T>, points[i], points[i+1]) == 0){
            i++;
        }
        points[m] == points[i];
        m++; // Update size of modified array
    }
    Polygon<T> hull;
    // If modified array of points has less than 3 points, convex hull is not possible
    if (m < 3){
        return hull;
    }

    // Create an empty stack and push first three points to it.
    vector<Point<T>> S;
    S.push_back(points[0]);
    S.push_back(points[1]);
    S.push_back(points[2]);

    // Process remaining n-3 points
    for (int i = 3; i < m; i++){
        // Keep removing top while the angle formed by points next-to-top, top, and points[i] makes a non-left turn
        while (S.size()>1 && orientation<T>(nextToTop<T>(S), S.back(), points[i]) != 2){
            S.pop_back();
        }
        S.push_back(points[i]);
    }

    // Now stack has the output points, add to hull the contents of stack
    for (int i = 0; i < S.size(); i++){
        hull.addPoint(S[i]);
    }
   return hull;
}