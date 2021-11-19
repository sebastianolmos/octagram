#include <fstream>
#include <math.h> 
#include "octagram/sampling/generation.hpp"
#include "octagram/util/random.hpp"
# define M_PI           3.14159265358979323846  /* pi */

void genRandomPoints(int n, std::string filepath, double maxDistance){
    RandomGenerator ranGen;
    std::ofstream file;
    file.open(filepath);
    for (int i = 0; i < n; i++){
        file << ranGen.getRandom(-maxDistance, maxDistance) << " " << ranGen.getRandom(-maxDistance, maxDistance) << "\n";
    }
    file.close();
}

Point<double>* createHullPoints(int n, float percent, double maxDistance){
    Point<double>* points = new Point<double>[n];
    int hull = (int)((double)n * percent);
    double angle = (2.0*M_PI)/((double)hull);
    for (int i = 0; i < hull; i++){
        points[i] = Point<double>(maxDistance*cos(angle*(double)i), maxDistance*sin(angle*(double)i));
    }
    int remain = n - hull;
    double inside = maxDistance * 0.8;
    RandomGenerator ranGen;
    for (int i = 0; i < remain; i++){
        double ranAngle = ranGen.getRandom(0.0, M_PI);
        double ranRadius = ranGen.getRandom(0.0, inside); 
        points[hull + i] = Point<double>(ranRadius*cos(ranAngle), ranRadius*sin(ranAngle));
    }
    return points;
}

void genHullPoints(int n, float percent, std::string filePath, double maxDistance){
    std::ofstream file;
    file.open(filePath);
    Point<double>* points = createHullPoints(n, percent, maxDistance);
    for (int i = 0; i < n; i++){
        file << points[i].getX() << " " << points[i].getY() << "\n";
    }
    file.close();
}