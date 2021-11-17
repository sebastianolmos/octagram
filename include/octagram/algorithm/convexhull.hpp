#include "octagram/point.hpp"
#include "octagram/segment.hpp"
#include "octagram/polygon.hpp"


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
    Segment<T> seg(p, q);
    if (seg.colinear(r)){
        return 0;
    }
    return (seg.left(r)) ? 2 : 1;
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