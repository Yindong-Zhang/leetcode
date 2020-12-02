//
// Created by so_go on 2020/7/19.
//
/*
 * 57. 插入区间

给出一个无重叠的 ，按照区间起始端点排序的区间列表。

在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。

示例 1:

输入: intervals = [[1,3],[6,9]], newInterval = [2,5]
输出: [[1,5],[6,9]]

示例 2:

输入: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
输出: [[1,2],[3,10],[12,16]]
解释: 这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。


 */
#ifndef UNTITLED_INSERT_57_H
#define UNTITLED_INSERT_57_H


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int L = newInterval[0], R= newInterval[1];
        int lt = L, rt = R;
        int i = 0;
        for(; i < intervals.size() and intervals[i][1] < L; ++i){
            res.push_back(intervals[i]);
        }
        for(;i < intervals.size() and intervals[i][1] >= L and intervals[i][0] <= R; ++i){
            lt = min(lt, intervals[i][0]);
            rt = max(rt, intervals[i][1]);
        }
        res.push_back({lt, rt});
        for(; i < intervals.size() and intervals[i][0] > R; ++i){
            res.push_back(intervals[i]);
        }
        return res;
    }
};
#endif //UNTITLED_INSERT_57_H
