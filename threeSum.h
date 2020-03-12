//
// Created by so_go on 2020/2/10.
//
/*
 * 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。



示例：

给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#ifndef SRC_THREESUM_H
#define SRC_THREESUM_H
#include<vector>
#include<algorithm>
using namespace std;

class ThreeSum {
public:

    // 二分查找
    /*
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for(auto pi = nums.begin(); pi < nums.end(); pi++){
            if(pi == nums.begin() or *pi != *(pi - 1)){
                for(auto pj = pi + 1; pj < nums.end(); pj++){
                    if(pj == pi + 1 or *pj != *(pj - 1)){
                        auto isFind = binary_search(pj + 1, nums.end(), - *pi - *pj);
                        if(isFind){
                            res.push_back({*pi, *pj, -*pi-*pj});
                        }
                    }

                }

            }
        }
        return res;
    }
     */

    // 双指针法
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++){
            if(i > 0 and nums[i] == nums[i - 1]){ // 跳过，剪枝搜索，避免重复
                continue;
            }
            int l = i + 1, r = nums.size() - 1;
            // 简化为一个双指针法的twoSum问题，最终复杂度是O(n^2)
            while(l < r){

                if(l > i + 1 and nums[l] == nums[l - 1] and r < nums.size() -1 and nums[r] == nums[r + 1]){ // 此处对搜索进行剪枝，跳过，避免重复结果
                    l++;
                    r--;
                    continue;
                }
                if(nums[l] + nums[r] > -nums[i]){
                    while(nums[l] + nums[r] > -nums[i] and l < r){
                        r--;
                    }
                }
                else if(nums[l] + nums[r] < -nums[i]){
                    while(nums[l] + nums[r] < -nums[i] and l < r){
                        l++;
                    }
                }
                else{
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                }
            }
        }
        return res;
    }
};
#endif //SRC_THREESUM_H
