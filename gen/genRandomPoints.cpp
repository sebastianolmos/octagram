#include<string>
#include "octagram/sampling/generation.hpp"

int main(){
    int sizes[5] = {100, 1000, 10000, 100000, 1000000};
    int samples = 10;
    for (int i = 0; i < 5; i++){
        std::string a = "../samples/points/random/p_";
        std::string b =  std::to_string(sizes[i]);
        for (int j = 0; j < samples; j++){
            std::string name;
            std::string c = "/s_";
            std::string d =  std::to_string(j+1);
            std::string e = ".txt";
            name.append(a);
            name.append(b);
            name.append(c);
            name.append(d);
            name.append(e);
            genRandomPoints(sizes[i], name, 1000);
        }
    }
    return 0;
}