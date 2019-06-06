cmake_minimum_required(VERSION 3.14)
project(src)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(src
        main.cpp
        copyRandomList.h hasCycleList.h title2Number.h fourSumCount.h randomizedSet.h kthSmallestInBinaryTree.h lowestCommonAncestor.h getIntersectNode.h reverseList.h)
