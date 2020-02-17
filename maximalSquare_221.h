//
// Created by so_go on 2020/2/13.
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

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximal-square
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#ifndef SRC_MAXIMALSQUARE_221_H
#define SRC_MAXIMALSQUARE_221_H
#include<vector>
#include<climits>
using namespace std;
class Solution {
public:

    // dp[i][j] = min(dp[i-1][j-1] + 1, R[i][j], C[i][j]) >> 可以简化为 dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1;
    int maximalSquare(vector<vector<char>>& matrix) {
        int nrows= matrix.size(), ncols= matrix[0].size();
        vector<vector<int>> R(nrows, vector<int>(ncols, 0)), C(nrows, vector<int>(ncols, 0));
        int rsum = 0, csum = 0;
        for(int i = 0; i < nrows; i++){
            rsum = 0;
            for(int j = 0; j < ncols; j++){
                if(matrix[i][j] == '0'){
                    rsum = 0;
                }
                else{
                    rsum += 1;
                }
                R[i][j] = rsum;
            }
        }

        for(int j = 0; j < ncols; j++){
            csum = 0;
            for(int i = 0; i < nrows; i++){
                if(matrix[i][j] == '1'){
                    csum += 1;
                }y
                }
                C[i][j] = csum;
            }
        }
        vector<vector<int>> dp(nrows, vector<int>(ncols, 0));
        for(int i = 0; i < nrows; i++)
            dp[i][0] = R[i][0];
        for(int j = 0; j < ncols; j++)
            dp[0][j] = C[0][j];

        int mx = INT_MIN;
        for(int i = 1; i < nrows; i++){
            for(int j = 1; j < ncols; j++){
                dp[i][j] = min(dp[i-1][j-1], min(R[i][j], C[i][j]));
                mx = max(mx, dp[i][j]);
            }
        }
        return mx * mx;
    }
};
#endif //SRC_MAXIMALSQUARE_221_H
