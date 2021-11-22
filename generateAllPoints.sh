#!/bin/bash

mkdir -p samples/points/hull_10/p_100
mkdir -p samples/points/hull_10/p_1000
mkdir -p samples/points/hull_10/p_10000
mkdir -p samples/points/hull_10/p_100000
mkdir -p samples/points/hull_10/p_1000000

mkdir -p samples/points/hull_30/p_100
mkdir -p samples/points/hull_30/p_1000
mkdir -p samples/points/hull_30/p_10000
mkdir -p samples/points/hull_30/p_100000
mkdir -p samples/points/hull_30/p_1000000

mkdir -p samples/points/hull_50/p_100
mkdir -p samples/points/hull_50/p_1000
mkdir -p samples/points/hull_50/p_10000
mkdir -p samples/points/hull_50/p_100000
mkdir -p samples/points/hull_50/p_1000000

mkdir -p samples/points/hull_70/p_100
mkdir -p samples/points/hull_70/p_1000
mkdir -p samples/points/hull_70/p_10000
mkdir -p samples/points/hull_70/p_100000
mkdir -p samples/points/hull_70/p_1000000

mkdir -p samples/points/hull_90/p_100
mkdir -p samples/points/hull_90/p_1000
mkdir -p samples/points/hull_90/p_10000
mkdir -p samples/points/hull_90/p_100000
mkdir -p samples/points/hull_90/p_1000000

mkdir -p samples/points/random/p_100
mkdir -p samples/points/random/p_1000
mkdir -p samples/points/random/p_10000
mkdir -p samples/points/random/p_100000
mkdir -p samples/points/random/p_1000000

cd bin

./genRandomPoints
./genHullPoints