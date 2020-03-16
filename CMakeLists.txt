cmake_minimum_required(VERSION 3.14)
project(src)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(src
        main.cpp
         removeDuplicates_80.h medianInTwoSortedArray_4.h threeSumClosest.h random10_470.h isMatch_44.h swapPairs_24.h isNumber_65.h)
