#pragma once
#include <random>
class RandomGenerator
{
public:
    RandomGenerator() : gen(std::random_device()()) {} // Seeds the mt19937.

    double getRandom(double min, double max){  
        std::uniform_real_distribution<double> dis(min, max);
        double random = dis(gen);
        return random;
    }

    int getRanInt(int min, int max){
        std::uniform_int_distribution<int> distrib(min, max);
        int random = distrib(gen);
        return random;
    }

private:
    std::mt19937 gen;
};