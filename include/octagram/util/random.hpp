#pragma once
#include <random>

class RandomGenerator
{
public:
    RandomGenerator::RandomGenerator() : gen(std::random_device()()) {} // Seeds the mt19937.

    double getRandom(double min, double max);

private:
    std::mt19937 gen;
};