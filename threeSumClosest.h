//
// Created by so_go on 2020/3/12.
//
/*
 * 16. 最接近的三数之和

给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).


 */
#ifndef SRC_THREESUMCLOSEST_H
#define SRC_THREESUMCLOSEST_H
#include<bits/stdc++.h>
#include<functional>
using namespace std;

class ThreeSumClosest {
public:
    /* 二分搜索，需要解决重复取样问题
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end(), less_equal<int>());
        vector<int> twoSum;
        for(int i = 0; i < nums.size(); ++i){
            for(int j = i + 1; j < nums.size(); ++j){
                twoSum.push_back(nums[i] + nums[j]);
            }
        }
        int res= INT_MAX;
        for(int &num : twoSum){
            int rsd = target - num;
            auto itr= lower_bound(nums.begin(), nums.end(), rsd);
            int diff;
            if(itr == nums.begin()){
                diff = *itr - rsd;
            }
            else if(itr == nums.end()){
                diff = rsd - *(itr - 1);
            }
            else{
                diff = min(*itr - rsd, rsd - *(itr - 1));
            }
            res = min(res, diff);
            if(res == 0){
                break;
            }
        }
        return res;
    }
     */
    // 双指针法, O(n^2) -> O(n), 实质是利用 O(n^2)解空间的性质进行快速排除
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end(), less_equal<int>());
        int  diff= INT_MAX, res;
        for(int i = 0; i < nums.size(); ++i){
            int l = i + 1, r = nums.size() - 1;
            int t_diff = INT_MAX, query = target - nums[i], t_res;
            while(l < r){
                if(nums[l] + nums[r] <= query){
                    if(query - nums[l] - nums[r] < t_diff){
                        t_diff = query - nums[l] -nums[r];
                        t_res = nums[i] + nums[l] + nums[r];
                    }
                    l++;
                }
                else{
                    if(nums[l] + nums[r] - query < t_diff){
                        t_diff = nums[l] + nums[r] - query;
                        t_res = nums[i] + nums[l] + nums[r];
                    }
                    r--;
                }
//                cout << i << ' ' << l << ' ' << r << ' ' << t_diff << ' ' << t_res  << endl;

                if(t_diff == 0){
                    break;
                }
            }
            if(t_diff < diff){
                res = t_res;
                diff = t_diff;
            }
            if(diff == 0){
                break;
            }
        }
        return res;
    }
};
#endif //SRC_THREESUMCLOSEST_H
