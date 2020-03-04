//
// Created by so_go on 2020/3/4.
//
/*
 * 面试题14- I. 剪绳子

给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m] 。请问 k[0]*k[1]*...*k[m] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

示例 1：

输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1

示例 2:

输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36

提示：

    2 <= n <= 58

注意：本题与主站 343 题相同：https://leetcode-cn.com/problems/integer-break/

 */
#ifndef SRC_CUTTINGROPE_343_H
#define SRC_CUTTINGROPE_343_H
#include<bits/stdc++.h>
using namespace std;

// f(n) = max(2 * f(n - 2), 3 * f(n - 3))

// 事实上， 最终可以证明，3f(n - 3) >= 2f(n - 2), 数学归纳法
class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(n + 1, 0);
        if(n == 2){
            return 1;
        }
        if(n == 3){
            return 2;
        }
        dp[1]= 1;
        dp[2]= 2;
        dp[3]= 3;
        for(int i = 4; i <= n; ++i){
            dp[i] = max(2 * dp[i - 2], 3 * dp[i - 3]);
        }
        return dp[n];
    }
};
#endif //SRC_CUTTINGROPE_343_H
