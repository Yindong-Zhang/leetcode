//
// Created by so_go on 2019/6/11.
//

#ifndef SRC_WIGGLESORT_H
#define SRC_WIGGLESORT_H
#include<vector>
#include<algorithm>
#include<cmath>
#include<iostream>
#include"printVector.h"
using namespace std;

class WiggleSort {
public:
    void wiggleSort2(vector<int> &nums) {
        if(nums.size() == 0){
            return;
        }
        sort(nums.begin(), nums.end());
        // 从排序的前半部分和后半部分分别倒序取数，填到列表中，注意是倒序
        // 中间位置开始为 ceil(nums.size() / 2.) - 1
        printVector(nums);
        vector<int> nums_cp = nums;
        int i = ceil(nums.size() / 2.) - 1, j = nums.size() - 1;
        for(int it = 0; it < nums.size(); it++){
            if( it % 2 == 0){
                nums[it] = nums_cp[i];
                i--;
            }
            else{
                nums[it] = nums_cp[j];
                j--;
            }
        }
    }
};
#endif //SRC_WIGGLESORT_H
