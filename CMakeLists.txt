cmake_minimum_required(VERSION 3.14)
project(src)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(src
        IsPalindrome.h
        main.cpp
        majorityNumber.h
        mergeSorted.h
        myBinarySearch.h
        partitionPalindrome.h
        searchMatrix.h
        superEggDrop.h
        TheNumberAppearONLYOnce.h
        wordBreak2.h
        wordBreak.h trie.h findword2.h isAnagram.h firstUniqueChar.h)
