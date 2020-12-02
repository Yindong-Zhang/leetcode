//
// Created by so_go on 2020/12/2.
//
/*
 * 665. 非递减数列

给你一个长度为 n 的整数数组，请你判断在 最多 改变 1 个元素的情况下，该数组能否变成一个非递减数列。

我们是这样定义一个非递减数列的： 对于数组中所有的 i (0 <= i <= n-2)，总满足 nums[i] <= nums[i + 1]。
 */
#ifndef SRC_NONDECREASINGARRAY_665_H
#define SRC_NONDECREASINGARRAY_665_H
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        return solve(nums);
    }
    bool solve(vector<int> nums){
        int mCnt = 0;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] >= nums[i - 1]){
                continue;
            }
            else{
                mCnt++;
                if(i > 1 and i < nums.size() - 1 and nums[i - 1] > nums[ i + 1] and nums[i - 2] > nums[i]){
                    //                cout << i << ' ' << endl;
                    return false;
                }
            }
            if(mCnt > 1){
                //            cout << '2' ;
                return false;
            }
        }
        return true;
    }
#endif //SRC_NONDECREASINGARRAY_665_H
