//
// Created by so_go on 2020/2/27.
//
/*
 * 80. 删除排序数组中的重复项 II

给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

示例 1:

给定 nums = [1,1,1,2,2,3],

函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。

你不需要考虑数组中超出新长度后面的元素。

示例 2:

给定 nums = [0,0,1,1,1,1,2,3,3],

函数应返回新长度 length = 7, 并且原数组的前五个元素被修改为 0, 0, 1, 1, 2, 3, 3 。

你不需要考虑数组中超出新长度后面的元素。

说明:
 */
#ifndef SRC_REMOVEDUPLICATES_H
#define SRC_REMOVEDUPLICATES_H

/* 核心代码：
 * for i in [0, n)
 * if nums[i] = curNum:
 *  if curCount <= 1:
 *      curCount++;
*     else:
 *     continue;
*   else nums[i] != curNum:
 *      curNum = nums[i]
 *      curCount = 1
 *   nums[j] = nums[i]
 *   j++
 */
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    // 双指针
    int removeDuplicates(vector<int>& nums) {
        int j= 0, lastNum = INT_MAX, lastCount = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == lastNum){
                if(lastCount <= 1){
                    lastCount++;
                }
                else{
                    continue;
                }
            }
            else{
                lastNum= nums[i];
                lastCount = 1;
            }
            nums[j++] = nums[i];

        }
        return j + 1;
    }
};
#endif //SRC_REMOVEDUPLICATES_H
