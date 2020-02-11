//
// Created by so_go on 2020/2/10.
//
/*
 * 给定一个未排序的整数数组，找出其中没有出现的最小的正整数。

示例 1:

输入: [1,2,0]
输出: 3

示例 2:

输入: [3,4,-1,1]
输出: 2

示例 3:

输入: [7,8,9,11,12]
输出: 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/first-missing-positive
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#ifndef SRC_FIRSTMISSINGPOSITIVE_H
#define SRC_FIRSTMISSINGPOSITIVE_H
#include<vector>
#include<cmath>
#include<climits>
using namespace std;

class FirstMissingPositive {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= 0){
                nums[i] = INT_MAX;
            }
        }
        for(int n : nums){
            n = abs(n);
            if(n <= nums.size() and nums[n - 1] > 0){
                nums[n - 1] = -nums[n - 1];
            }
        }

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};
#endif //SRC_FIRSTMISSINGPOSITIVE_H
