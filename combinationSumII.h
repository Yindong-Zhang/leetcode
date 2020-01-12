//
// Created by so_go on 2020/1/12.
//
/*
 * 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

    所有数字（包括目标数）都是正整数。
    解集不能包含重复的组合。

示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]

示例 2:

输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#ifndef SRC_COMBINATIONSUMII_H
#define SRC_COMBINATIONSUMII_H
#include<vector>
#include<algorithm>
#include"printVector.h"
using namespace std;
// 回溯dfs + 剪枝
class CombinationSumII {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> comb;
        vector<bool> isUsed(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        printVector(candidates);
        dfs(candidates, candidates.size(), target, res, comb);
        return res;
    }

    void dfs(vector<int> &candidates, int index, int target, vector<vector<int>> &res,  vector<int> cmb){
        if(target < 0){
            return;
        }
        if(target == 0){
            res.push_back(cmb);
            return;
        }

        for(int i = index - 1; i >= 0; i--){
            if( i + 1 < index and candidates[i] == candidates[i + 1]){
                continue;
            }
            cmb.push_back(candidates[i]);
            dfs(candidates, i, target - candidates[i], res, cmb);
            cmb.pop_back();
        }

    }
};
#endif //SRC_COMBINATIONSUMII_H
