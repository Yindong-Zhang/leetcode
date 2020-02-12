cmake_minimum_required(VERSION 3.14)
project(src)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(src
        main.cpp
         isHappyNumber.h getSumWithoutAdd.h stockChangeIII.h stockChangeI.h stockChangeII.h russianDollEnvelops.h waterTrap.h combinationSumII.h permute.h permuteUnique.h preOrderSerializeDeserializeBinaryTree.h countDigitOne.h nextPermutatioin.h isMatch.h findDisappearedNumbers.h FirstMissingPositive.h threeSum.h Pow.h sumSubarrayMins.h splitArray.h minWindow_76.h)
