//
// Created by so_go on 2020/1/10.
//
/*
 * 给定一些标记了宽度和高度的信封，宽度和高度以整数对形式 (w, h) 出现。当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。

请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。

说明:
不允许旋转信封。

 输入: envelopes = [[5,4],[6,4],[6,7],[2,3]]
输出: 3
解释: 最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。
 */
#ifndef SRC_RUSSIANDOLLENVELOPS_H
#define SRC_RUSSIANDOLLENVELOPS_H
#include<algorithm>
#include<vector>
#include<climits>
#include<iostream>
using namespace std;
// 比较 a < b
bool comp(vector<int> a, vector<int> b){
    if(a[0] < b[0]){
        return true;
    }
    else if(a[0] == b[0] and a[1] < b[1]){
        return true;
    }
    else{
        return false;
    }
}
class russianDollEnvelops {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int nEnvs = envelopes.size();
        if(nEnvs == 0){
            return 0;
        }
        sort(envelopes.begin(), envelopes.end(),comp);

        return solve(envelopes);
    }

    int solve(vector<vector<int>>  envelops){
        vector<int> dp(envelops.size(), 0);
        for(int i = 0; i < dp.size(); i++){
            int tmpMax = 0;
            for(int j = 0; j < i; j++){
                if( envelops[j][0] < envelops[i][0] and envelops[j][1] < envelops[i][1]){
                    tmpMax = max(tmpMax, dp[j]);
                }
            }
            dp[i] = tmpMax + 1;
        }
        return *max_element(dp.begin(), dp.end());
    }
    /* 尝试使用 在k处长度为i的 Longest Incresing sequence 的最小值 这一状态定义，发现是错的。
     * 该题的本质是在偏序有向图上的最长序列问题
     * 状态定义
    int longestIncresingSubsequence(vector<vector<int>> l){
        vector<vector<int>> dp(l.size(), {INT_MAX, INT_MAX});
        for(auto li: l){
            int i = 0;
            while(dp[i][0] < li[0] and dp[i][1] < li[1]){
                i++;
            }
            dp[i] = comp(dp[i], li) ? dp[i] : li;
        }
        int resInd = 0;
        while(resInd < dp.size() and dp[resInd][0] != INT_MAX){
            resInd++;
        }
        return resInd;
    }


    int longestIncresingSubsequence(vector<int> l){
        vector<int> dp(l.size(), INT_MAX);
        for(auto li: l){
            int i = 0;
            while(dp[i] < li){
                i++;
            }
            dp[i] = li;
        }
        int resInd = 0;
        while(resInd < dp.size() and dp[resInd] != INT_MAX){
            resInd++;
        }
        return resInd;
    }
    */


};
#endif //SRC_RUSSIANDOLLENVELOPS_H
