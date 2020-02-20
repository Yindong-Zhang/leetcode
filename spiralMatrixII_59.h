//
// Created by so_go on 2020/2/18.
//
/*
 * 给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:

输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/spiral-matrix-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#ifndef SRC_SPIRALMATRIXII_59_H
#define SRC_SPIRALMATRIXII_59_H
#include<vector>
using namespace std;

class Solution {
public:
    // 题目给定正方形，可以简化判断
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int it = 0, cnt = 1;
        while(it <= n - 1 - it){
            for(int j = it; j <= n - 1 - it; j++){
                res[it][j] = cnt++;
            }
            for(int i = it + 1; i <= n - 1 - it; i++){
                res[i][n - 1 - it] = cnt++;
            }
            for(int j = n - 2 - it; j >= it; j--){
                res[n-1-it][j] = cnt++;
            }
            for(int i= n - 2 - it; i > it; i--){
                res[i][it] = cnt++;
            }
        }
        return res;
    }
};
#endif //SRC_SPIRALMATRIXII_59_H
