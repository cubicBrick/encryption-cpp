echo off
cd ./objects
g++ -c ../utility/bigint/*.cpp ../testing/test.cpp
cd ..
g++ ./objects/*.o -o main.exe