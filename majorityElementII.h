//
// Created by so_go on 2020/3/30.
//
/*
 * 229. 求众数 II

给定一个大小为 n 的数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。

说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1)。

示例 1:

输入: [3,2,3]
输出: [3]

示例 2:

输入: [1,1,1,3,3,2,2,2]
输出: [1,2]


 */
#ifndef SRC_MAJORITYELEMENTII_H
#define SRC_MAJORITYELEMENTII_H
#include<bits/stdc++.h>
using namespace std;
/* if c = a : ca++, continue;
 if c = b : cb++, continue;
 if ca == 0: a = num, ca++; conintue;
 if cb == 0: b = num, cb++, continue;
 else
    ca--;
    cb--;
    */
//
class MajorityElementII{
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a, b;
        int ca = 0, cb = 0;
        for(auto num : nums){
            if(num == a and ca != 0){
                ca++;
                continue;
            }
            if(num == b and cb != 0){
                cb++;
                continue;
            }
            if(ca == 0){
                a = num;
                ca++;
                continue;
            }
            if(cb == 0){
                b = num;
                cb++;
                continue;
            }
            ca--;
            cb--;
            // 实际就是找三个不同的数，然后消去，如果存在复合条件的数字，必然在剩下的数字里。
//            cout << num << endl;
//            cout << a << ' ' << b << endl;
//            cout << ca << ' ' << cb << endl;
        }
        vector<int> res;
        if(ca == 0 and cb == 0){
            return res;
        }
        else{
            if(ca != 0){
                ca = 0;
                for(auto num: nums){
                    if(num == a){
                        ca++;
                    }
                }
                if(ca > nums.size() / 3){
                    res.push_back(a);
                }
            }
            if(cb != 0){
                cb = 0;
                for(auto num: nums){
                    if(num == b){
                        cb++;
                    }
                }
                if(cb > nums.size() / 3){
                    res.push_back(b);
                }
            }

        }
        return res;
    }
};
#endif //SRC_MAJORITYELEMENTII_H
