//
// Created by so_go on 2020/3/17.
//
/*
 * 39. 组合总和

给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

    所有数字（包括 target）都是正整数。
    解集不能包含重复的组合。

示例 1:

输入: candidates = [2,3,6,7], target = 7,
所求解集为:
[
  [7],
  [2,2,3]
]

示例 2:

输入: candidates = [2,3,5], target = 8,
所求解集为:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

通过次数72,781
提交次数106,144
在真实的面试中遇到过这道题？
 */
#ifndef SRC_COMBINATIONSUMI_39_H
#define SRC_COMBINATIONSUMI_39_H
#include<bits/stdc++.h>
using namespace std;

class CombinationSum39 {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> v;
        dfs(candidates, target, v, res, 0);
        return res;
    }

    void dfs(vector<int> &candidates, int target, vector<int> &v, vector<vector<int>> &res, int start){
        if(target == 0){
            res.push_back(v);
        }
        for(int i = start; i < candidates.size(); ++i){
            if(target - candidates[i] < 0){
                continue;
            }
            v.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], v, res, i);
            v.pop_back();
        }
    }
};
#endif //SRC_COMBINATIONSUMI_39_H
