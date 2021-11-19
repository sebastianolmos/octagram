#include <chrono>
#include <random>
#include "octagram/util/random.hpp"

double RandomGenerator::getRandom(double min, double max){  
    std::uniform_real_distribution<double> dis(min, max);
    double randomN = dis(gen);
    return randomN;
}