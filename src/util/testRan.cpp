#include <iostream>
#include "octagram/util/random.hpp"

int main() {
    RandomGenerator ranGen;
    double* test = new double[1000000];
    for( int j = 0; j < 1000000; j++ )
    {
        test[j] = ranGen.getRandom(1.0, 5.0);
    }
    std::cout << test[1000000 - 1]<< std::endl;
    return 0;
}