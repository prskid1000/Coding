#!/bin/bash
#!chmod +x  StressTest.sh

g++ SolGen.cpp -o SolGen
g++ Naive.cpp -o Naive
g++ Expert.cpp -o Expert
./SolGen < GenData.txt > input.txt
./Naive < input.txt > Naive.txt
./Expert < input.txt > Expert.txt
diff Naive.txt Expert.txt > Result.txt
echo "Testing Done"
