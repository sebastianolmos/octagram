#include<string>
#include "octagram/sampling/generation.hpp"

int main(){
    int pNames[5] = {10, 30, 50, 70, 90};
    double percents[5] = {0.1, 0.3, 0.5, 0.7, 0.9};
    int sizes[5] = {100, 1000, 10000, 100000, 1000000};
    int samples = 10;
    for (int i = 0; i < 5; i++){
        std::string a = "../../samples/points/hull_";
        std::string b =  std::to_string(pNames[i]);
        for (int j = 0; j < 5; j++){
            std::string c = "/p_";
            std::string d = std::to_string(sizes[j]);
            for (int k = 0; k < samples; k++){
                std::string e = "/s_";
                std::string f =  std::to_string(k+1);
                std::string g = ".txt";
                std::string name;
                name.append(a);
                name.append(b);
                name.append(c);
                name.append(d);
                name.append(e);
                name.append(f);
                name.append(g);
                genHullPoints(sizes[j], percents[i], name, 1000);
            }
        }
    }
    return 0;
}