cmake_minimum_required(VERSION 3.14)
project(src)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(src
        main.cpp
        findOrder.h singleNumber.h maxPointCollinear.h fraction2Decimal.h factorialTrailingZero.h reverseBIts.h hammingWeight.h countPrime.h)
