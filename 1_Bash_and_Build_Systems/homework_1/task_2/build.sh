#!/usr/bin/env bash
echo "Building the arithmetic library....."
rm -rf build
mkdir build
c++ -c -I include src/subtract.cpp -o build/subtract.o
c++ -c -I include src/sum.cpp -o build/sum.o

ar rcs build/libipb_arithmetic.a build/sum.o build/subtract.o 
echo "Done"
echo "Building the example program....."
c++ -std=c++17 src/main.cpp -I ./include/ -L ./build/ -lipb_arithmetic -o ./results/example_output
echo "Done"
echo "-----------------------------------------"
./results/example_output 