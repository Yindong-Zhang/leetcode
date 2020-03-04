//
// Created by so_go on 2020/3/4.
//
/*
 * 面试题14- II. 剪绳子 II

给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m] 。请问 k[0]*k[1]*...*k[m] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。



示例 1：

输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1

示例 2:

输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36



提示：

    2 <= n <= 1000

 */
#ifndef SRC_CUTTINGROPEII_H
#define SRC_CUTTINGROPEII_H
// 由于需要取mod，如果采用递推公式
// f(n) = max(2 * f(n - 2), 3 f(n - 3)), 取模与求最大值符号无法交换
// 如前所述，事实上，在一般情况下， f(n) = 3 f(n - 3), 小数情况下需要特殊讨论
#include<bits/stdc++.h>
#define M (1E9+7) // ~(<) 2^30 ( INT_MAX / 2)
using namespace std;

class Solution {
public:
    int f(int n){
        if(n == 2){
            return 2;
        }
        if(n== 3){
            return 3;
        }
        if(n == 4){
            return 4;
        }
        int fn_3= f(n - 3);
        return ((2 * fn_3) % (int)M + fn_3) % (int)M ;
    }
    int cuttingRope(int n) {
        if(n == 2){
            return 1;
        }
        if(n == 3){
            return 2;
        }
        if(n == 4){
            return 4;
        }
        return f(n);
    }
};
#endif //SRC_CUTTINGROPEII_H
