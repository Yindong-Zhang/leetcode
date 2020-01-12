//
// Created by so_go on 2020/1/12.
//
/*
 * 给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例:

输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#ifndef SRC_PERMUTEUNIQUE_H
#define SRC_PERMUTEUNIQUE_H
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
class PermuteUnique {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(nums, 0, res);
        return res;
    }

//    回溯递归， 剪枝搜索
    void dfs(vector<int> &nums, int i, vector<vector<int>> &res){
        if( i == nums.size() - 1){
            res.push_back(nums);
            return;
        }
        set<int> N;
        for(int j = i; j < nums.size(); j++){
            if(N.find(nums[j]) == N.end()){
                N.insert(nums[j]);
                swap(nums[i], nums[j]);
                dfs(nums, i + 1, res);
                swap(nums[i], nums[j]);
            }
        }
    }
};
#endif //SRC_PERMUTEUNIQUE_H
