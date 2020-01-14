//
// Created by so_go on 2020/1/13.
//
/*
 * 给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数。

示例:

输入: 13
输出: 6
解释: 数字 1 出现在以下数字中: 1, 10, 11, 12, 13 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-digit-one
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#ifndef SRC_COUNTDIGITONE_H
#define SRC_COUNTDIGITONE_H
#include<cmath>
using namespace std;
class CountDigitOne {
public:
    /*
     *
     理解错误，理解成出现1的数字的个数
    int f(int k){
        int res = 0;
        for(int i = 0; i <= k - 1; i++){
            int tmp = pow(10, i) * pow(9, k - 1 - i);
            res += tmp;
        }
        return res;
    }
    int countDigitOne(int n) {
        int digit, newn = n, ws = 0;
        while(newn > 0){
            digit = newn % 10;
            ws += 1;
            newn = newn / 10;
        }
        cout << n << ' ' << digit << ' ' << ws << endl;
        int curNum;
        if(n == 0){
            return 0;
        }
        if(ws == 1){
            return 1;
        }
        if( ws > 1 and digit == 1){
            return f(ws - 1) + n - digit * pow(10, ws - 1) + 1;
        }
        else{
            curNum = pow(10, ws - 1) + (digit - 1) * f( ws - 1);
            return curNum + countDigitOne(n - digit * pow(10, ws - 1));
        }
    }
     */
};
#endif //SRC_COUNTDIGITONE_H
