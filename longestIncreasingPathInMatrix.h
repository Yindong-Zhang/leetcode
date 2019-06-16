//
// Created by so_go on 2019/6/16.
//

#ifndef SRC_LONGESTINCREASINGPATHINMATRIX_H
#define SRC_LONGESTINCREASINGPATHINMATRIX_H
#include<vector>
#include"printMatrix.h"
using namespace std;
class LongestIncreasingPathinMatrix {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if( matrix.size() == 0){
            return 0;
        }
        if(matrix[0].size() == 0){
            return 0;
        }
        int nrows = matrix.size(), ncols = matrix[0].size();
        vector<vector<int>> dp(nrows, vector<int>(ncols, 1));
        vector<vector<int>> dp_st = dp;
        bool ischange = true;
        int cur, cur_dp;
        while(ischange){
            ischange = false;
            for(int i = 0; i < nrows; i++){
                for(int j = 0; j < ncols; j++){
                    cur = matrix[i][j];
                    cur_dp = dp[i][j];
                    if( i > 0 and matrix[i - 1][j] < cur and 1 + dp[i - 1][j] > cur_dp){
                        cur_dp = 1 + dp[i-1][j];
                        ischange = true;
                    }
                    if( i < nrows - 1 and matrix[i + 1][j] < cur and 1 + dp[i + 1][j] > cur_dp){
                        cur_dp = 1 + dp[i + 1][j];
                        ischange = true;
                    }
                    if( j > 0 and matrix[i][j - 1] < cur and 1 + dp[i][j - 1] > cur_dp){
                        cur_dp = 1 + dp[i][j - 1];
                        ischange = true;
                    }
                    if( j < ncols - 1 and matrix[i][j + 1] < cur and 1 + dp[i][j + 1] > cur_dp){
                        cur_dp = 1 + dp[i][j + 1];
                        ischange = true;
                    }
                    dp_st[i][j] = cur_dp;
                }
            }
            dp = dp_st;
//            printMatrix(dp);
        }

        int max = 0;
        for(int i = 0; i < nrows; i++)
            for(int j = 0; j < ncols; j++){
                if(dp[i][j] > max){
                    max = dp[i][j];
                }
            }
        return max;
    }
};
#endif //SRC_LONGESTINCREASINGPATHINMATRIX_H
