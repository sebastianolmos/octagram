#pragma once
#include<string>
#include "octagram/point.hpp"

void genRandomPoints(int n, std::string filepath, double maxDistance);

Point<double>* createHullPoints(int n, float percent, double maxDistance);

void genHullPoints(int n, float percent, std::string filePath, double maxDistance);