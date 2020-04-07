//
// Created by so_go on 2020/4/6.
//
/*
 * 给出一个区间的集合，请合并所有重叠的区间。

示例 1:

输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].

示例 2:

输入: [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-intervals
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#ifndef SRC_MERGERANGE_H
#define SRC_MERGERANGE_H
#include<bits/stdc++.h>
using namespace std;
// 重叠计数，重叠为1 -> 0， 记录区别有边界， 重叠 0 -> 1 记录区间左边界。
struct Record{
    int n;
    bool isBegin;
    bool operator < (const Record & b) const{
        if(n < b.n){
            return true;
        };
        if(n == b.n and isBegin and not b.isBegin){ // 为了避免两个区间右边界和左边界重叠的情况，此处要特别小心
            return true;
        }
        return false;
    }
};
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        vector<Record> Rs;
        for(auto &p : intervals){
            Rs.push_back({p[0], true});
            Rs.push_back({p[1], false});
        }
        sort(Rs.begin(), Rs.end());
        int overlapCount = 0;
        int l, r;
        for(int i = 0; i < Rs.size(); ++i){
            Record rd = Rs[i];
            if(rd.isBegin){
                if(overlapCount == 0){
                    l = rd.n;
                }
                overlapCount++;
            }
            else{
                if(overlapCount == 1){
                    r = rd.n;
                    res.push_back({l, r});
                }
                overlapCount--;
            }
        }
        return res;
    }
};
#endif //SRC_MERGERANGE_H
