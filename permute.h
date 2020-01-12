//
// Created by so_go on 2020/1/12.
//
/*
 * 给定一个没有重复数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#ifndef SRC_PERMUTE_H
#define SRC_PERMUTE_H
#include<vector>
#include<algorithm>
using namespace std;
class Permute {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(nums, 0, res);
        return res;
    }

    void dfs(vector<int> &nums, int i, vector<vector<int>> &res){
        if(i == nums.size() - 1){
            res.push_back(nums);
            return;
        }
        for(int j = i; j < nums.size(); j++){
            swap(nums[i], nums[j]);
            dfs(nums, i + 1, res);
            swap(nums[j], nums[i]);
        }
    }
};

#endif //SRC_PERMUTE_H
