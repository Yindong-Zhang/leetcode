//
// Created by so_go on 2019/5/29.
//

#ifndef SRC_MEDIANFINDER_H
#define SRC_MEDIANFINDER_H
#include<vector>
using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    vector<int> vec;
    void addNum(int num) {
        if(vec.empty()){
            vec.push_back(num);
        }
        else{
            // TODO:
        }
    }

    double findMedian() {

    }
};
#endif //SRC_MEDIANFINDER_H
