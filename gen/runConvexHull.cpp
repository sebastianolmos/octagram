#include <iostream>
#include <fstream>
#include <string>
#include "octagram/point.hpp"
#include "octagram/polygon.hpp"
#include "octagram/algorithm/convexhull.hpp"
#include "octagram/sampling/timer.hpp"

int main(int argc, char *argv[]){
    if (argc < 4){
        std::cout << "Have to pass [distribution] [n] [algorithm]" << std::endl;
        return 0;
    }
    int n;
    std::string dist;
    int algorithm;
    std::string algorithmName;

    /*
    first parameter is for picking the distribution
    0: random
    1: 10% of points in hull
    2: 30% of points in hull
    3: 50% of points in hull
    4: 70% of points in hull
    5: 90% of points in hull
    */
    switch (std::atoi(argv[1]))
    {
    case 0:
        dist = "random/";
        break;
    case 1:
        dist = "hull_10/";
        break;
    case 2:
        dist = "hull_30/";
        break;
    case 3:
        dist = "hull_50/";
        break;
    case 4:
        dist = "hull_70/";
        break;
    case 5:
        dist = "hull_90/";
        break;
    default:
        return 0;
    }

    /*
    second parameter is for picking the n
    */
    switch (std::atoi(argv[2]))
    {
    case 100:
        n = 100;
        break;
    case 1000:
        n = 1000;
        break;
    case 10000:
        n = 10000;
        break;
    case 100000:
        n = 100000;
        break;
    case 1000000:
        n = 1000000;
        break;
    default:
        return 0;
    }

    /*
    third parameter is for picking the convex hull algorithm
    0: Gift Wrapping
    1: Graham Scan
    */
    switch (std::atoi(argv[3]))
    {
    case 0:
        algorithm = 0;
        algorithmName = "GF_";
        break;
    case 1:
        algorithm = 1;
        algorithmName = "GH_";
        break;
    default:
        return 0;
    }

    std::string filesToRead;
    std::string a = "../../samples/points/";
    std::string b = "p_";
    std::string c = std::to_string(n);
    filesToRead.append(a);
    filesToRead.append(dist);
    filesToRead.append(b);
    filesToRead.append(c);

    std::string fileToWrite;
    std::string w_a = "../../samples/times/";
    std::string w_c = ".txt";
    fileToWrite.append(w_a);
    fileToWrite.append(dist);
    fileToWrite.append(algorithmName);
    fileToWrite.append(c);
    fileToWrite.append(w_c);

    std::ofstream outFile;
    outFile.open(fileToWrite);

    int samples = 10;
    for (int i = 0; i < samples; i++){
        // Procces a points sample
        std::string name;
        std::string d = "/s_";
        std::string e = std::to_string(i+1);
        std::string f = ".txt";
        name.append(filesToRead);
        name.append(d);
        name.append(e);
        name.append(f);
        double x, y;
        std::ifstream inFile(name);
        Point<double>* points = new Point<double>[n];
        int c = 0;
        Timer timer;

        while (inFile >> x >> y)
        {
            // Add points to the Polygon
            points[c] = Point<double>(x, y);
            c++;
        }
        Polygon<double> hull;
        if (algorithm == 0){
            timer.start();
            hull = giftWrapping(points, n);
            timer.stop();
        }
        else {
            timer.start();
            hull = grahamScan(points, n);
            timer.stop();
        }
        outFile << timer.elapsedMilliseconds() << "\n";
        
        std::cout << "-------> Points procceced <--------"<< std::endl;
        std::cout << "c: " << 2.356 << std::endl;
        std::cout << "time: " << (double)timer.elapsedMilliseconds() << std::endl;
        std::cout << "hull size: " << hull.getCount() << std::endl;
    }
    outFile.close();
    return 0;
}