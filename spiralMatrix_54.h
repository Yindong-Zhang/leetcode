//
// Created by so_go on 2020/2/17.
//
/*
 * 54. 螺旋矩阵

给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

示例 1:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]

示例 2:

输入:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]


 */
#ifndef SRC_SPIRALMATRIX_54_H
#define SRC_SPIRALMATRIX_54_H
#include<vector>
using namespace std;
class SpiralMatrix {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size() == 0){
            return res;
        }
        int m = matrix.size() - 1, n = matrix[0].size() - 1;
        int it = 0;
        while(it <= m - it and it <= n - it){
            for(int j = it; j < n - it; j++){
                res.push_back(matrix[it][j]);
            }
            for(int i = it; i <= m - it; i++){
                res.push_back(matrix[i][n - it]);
            }
            if(it < m - it and it < n - it){
                for(int j = n - it - 1; j >= it; j--){
                    res.push_back(matrix[m - it][j]);
                }
                for(int i = m - it - 1; i > it; i--){
                    res.push_back(matrix[i][it]);
                }
            }
            it++;
        }
        return res;
    }


};
#endif //SRC_SPIRALMATRIX_54_H
