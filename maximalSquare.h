//
// Created by so_go on 2020/9/3.
//
/*
 * 在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。

示例:

输入:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

输出: 4


 */
#ifndef SRC_MAXIMALSQUARE_H
#define SRC_MAXIMALSQUARE_H
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int res = 0;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(matrix[i - 1][j - 1] == '0'){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res;
    }
};
#endif //SRC_MAXIMALSQUARE_H
