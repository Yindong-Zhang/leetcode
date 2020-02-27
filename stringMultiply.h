//
// Created by so_go on 2020/2/27.
//
/*
 * 43. 字符串相乘

给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"

示例 2:

输入: num1 = "123", num2 = "456"
输出: "56088"

说明：

    num1 和 num2 的长度小于110。
    num1 和 num2 只包含数字 0-9。
    num1 和 num2 均不以零开头，除非是数字 0 本身。
    不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。


 */
#ifndef SRC_STRINGMULTIPLY_H
#define SRC_STRINGMULTIPLY_H
#include<vector>
#include<string>
#include"printVector.h"
#include<iostream>
using namespace std;
class StringMultiply {
public:
    /*
    string multiply(string num1, string num2) {
        vector<int> num1_vec, num2_vec;
        for(int i = num1.size() - 1; i >= 0; --i){
            num1_vec.push_back(num1[i] - '0');
        }
        for(int j = num2.size() - 1; j >= 0; --j){
            num2_vec.push_back(num2[j] - '0');
        }
        vector<int> res(num1.size() + num2.size(), 0);
        for(int k = 0; k < num1.size() + num2.size() - 1; ++k ){
            int n_k = 0;
            for(int i = 0; i <= k ; i++){
                if(i < num1_vec.size() and k - i < num2_vec.size()){
                    n_k += num1_vec[i] * num2_vec[k - i];
                }
            }
            cout << k << ' ' << n_k << endl;
            int jw= 0, ki = k, gw= n_k % 10;
            while(n_k > 0 or jw > 0){
                int tmp = res[ki] + gw + jw;
                res[ki] = tmp % 10;
                jw = tmp / 10;
                n_k = n_k / 10;
                gw = n_k % 10;
                ki++;
            }
            printVector(res);
        }
        string ret;

        if(res[res.size() - 1] != 0){
            ret.push_back('0' + res[res.size() - 1]);
        }
        for(int i = res.size() - 2; i >= 0; --i){
            ret.push_back('0' + res[i]);
        }
        return ret;
    }
    */

    // 更简洁的写法
    // a * b = sum(a[i] * 10^i) * sum(b[j] * 10^j) = sum_i(sum_j a[i] * b[j] * 10^(i + j))
    void add(vector<int> &res, int n, int k){
        int jw = 0, ki = k;
        while(n > 0 or jw > 0){
            int tmp = res[ki] + n % 10 + jw;
            res[ki] = tmp % 10;
            jw = tmp / 10;
            n = n / 10;
            ki++;
        }
    }

    string multiply(string num1, string num2){
        if(num1 == "0" or num2 == "0"){
            return "0";
        }
        vector<int> num1_vec, num2_vec;
        for(int i = num1.size() - 1; i >= 0; --i){
            num1_vec.push_back(num1[i] - '0');
        }
        for(int j = num2.size() - 1; j >= 0; --j){
            num2_vec.push_back(num2[j] - '0');
        }
        vector<int> res(num1.size() + num2.size(), 0);
        for(int i = 0; i < num1_vec.size(); ++i){
            for(int j = 0; j < num2_vec.size(); ++j){
                int tmp= num1_vec[i] * num2_vec[j];
                add(res, tmp, i + j);
            }
        }
        string ret;
        if(res[res.size() - 1] != 0){
            ret.push_back('0' + res[res.size() - 1]);
        }
        for(int i = res.size() - 2; i >= 0; --i){
            ret.push_back('0' + res[i]);
        }
        return ret;
    }
};
#endif //SRC_STRINGMULTIPLY_H
