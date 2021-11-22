#include <fstream>
#include <math.h> 
#include <algorithm>  
#include <limits>
#include <iomanip>
#include "octagram/sampling/generation.hpp"
#include "octagram/util/random.hpp"
# define M_PI           3.14159265358979323846  /* pi */

void genRandomPoints(int n, std::string filepath, double maxDistance){
    int c = 0;

    RandomGenerator ranGen;
    std::ofstream file;
    file.open(filepath);
    for (int i = 0; i < n; i++){
        file << std::setprecision(std::numeric_limits<long double>::digits10 + 1) << ranGen.getRandom(-maxDistance, maxDistance) << " " << ranGen.getRandom(-maxDistance, maxDistance) << "\n";
    }
    file.close();
}

Point<double>* createHullPoints(int n, float percent, double maxDistance){
    Point<double>* points = new Point<double>[n];
    int hull = (int)((double)n * percent);
    double angle = (2.0*M_PI)/((double)hull);
    for (int i = 0; i < hull; i++){
        double tmpAngle = angle*(double)i;
        points[i] = Point<double>(maxDistance*(double)cos(tmpAngle), maxDistance*(double)sin(tmpAngle));
    }
    int remain = n - hull;
    double inside = maxDistance * 0.8;
    RandomGenerator ranGen;
    for (int i = 0; i < remain; i++){
        double ranAngle = ranGen.getRandom(0.0, 2.0*M_PI);
        double ranRadius = ranGen.getRandom(0.0, inside); 
        points[hull + i] = Point<double>(ranRadius*(double)cos(ranAngle), ranRadius*(double)sin(ranAngle));
    }
    return points;
}

void genHullPoints(int n, float percent, std::string filePath, double maxDistance){
    long double* xs = new long double[n];
    long double* ys = new long double[n];
    int* is = new int[n];
    int c = 0;

    int hull = (int)((double)n * percent);
    long double angle = (2.0L*M_PI)/((long double)hull);

    for (int i = 0; i < hull; i++){
        long double tmpAngle = angle*(long double)i;
        xs[c] = (long double)maxDistance*(long double)cos(tmpAngle);
        ys[c] = (long double)maxDistance*(long double)sin(tmpAngle);
        is[c] = c;
        c++;
    }

    int remain = n - hull;
    double inside = maxDistance * 0.8;
    RandomGenerator ranGen;
    for (int i = 0; i < remain; i++){
        long double ranAngle = ranGen.getRandom(0.0, 2.0*M_PI);
        long double ranRadius = ranGen.getRandom(0.0, inside); 
        xs[c] = (long double)ranRadius*(long double)cos(ranAngle);
        ys[c] = (long double)ranRadius*(long double)sin(ranAngle);
        is[c] = c;
        c++;
    }
    std::random_shuffle(is, is + n);

    std::ofstream file;
    file.open(filePath);
    for (int i = 0; i < c; i++){
        file << std::setprecision(std::numeric_limits<long double>::digits10 + 1) << xs[is[i]] << " " << ys[is[i]] << "\n";
    }
    file.close();
}
