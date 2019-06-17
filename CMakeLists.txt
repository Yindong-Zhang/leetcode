cmake_minimum_required(VERSION 3.14)
project(src)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(src
        main.cpp
        kRepeatedLongestSubstring.h longestConsecutive.h numSquares.h lengthOfLIS.h coinChange.h longestIncreasingPathInMatrix.h printMatrix.h ladderlength.h numIslands.h)
