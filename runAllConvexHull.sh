#!/bin/bash

mkdir -p samples/times/random
mkdir -p samples/times/hull_10
mkdir -p samples/times/hull_30
mkdir -p samples/times/hull_50
mkdir -p samples/times/hull_70
mkdir -p samples/times/hull_90

cd bin

for i in 1 2 3 4 5
do
    for j in 100 1000 10000 100000 1000000
    do
        for k in 0 1
        do
            ./runConvexHull $i $j $k
        done
    done
done