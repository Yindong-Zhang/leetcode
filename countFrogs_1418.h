//
// Created by so_go on 2020/4/20.
//
/*
 * 5390. 数青蛙

给你一个字符串 croakOfFrogs，它表示不同青蛙发出的蛙鸣声（字符串 "croak" ）的组合。由于同一时间可以有多只青蛙呱呱作响，所以 croakOfFrogs 中会混合多个 “croak” 。请你返回模拟字符串中所有蛙鸣所需不同青蛙的最少数目。

注意：要想发出蛙鸣 "croak"，青蛙必须 依序 输出 ‘c’, ’r’, ’o’, ’a’, ’k’ 这 5 个字母。如果没有输出全部五个字母，那么它就不会发出声音。

如果字符串 croakOfFrogs 不是由若干有效的 "croak" 字符混合而成，请返回 -1 。



示例 1：

输入：croakOfFrogs = "croakcroak"
输出：1
解释：一只青蛙 “呱呱” 两次

示例 2：

输入：croakOfFrogs = "crcoakroak"
输出：2
解释：最少需要两只青蛙，“呱呱” 声用黑体标注
第一只青蛙 "crcoakroak"
第二只青蛙 "crcoakroak"

示例 3：

输入：croakOfFrogs = "croakcrook"
输出：-1
解释：给出的字符串不是 "croak" 的有效组合。

示例 4：

输入：croakOfFrogs = "croakcroa"
输出：-1



提示：

    1 <= croakOfFrogs.length <= 10^5
    字符串中的字符只有 'c', 'r', 'o', 'a' 或者 'k'


 */
#ifndef SRC_COUNTFROGS_1418_H
#define SRC_COUNTFROGS_1418_H
#include<bits/stdc++.h>
using namespace std;
// 双百解答，记录c r o a k 的个数，保证是一个单调不增序列，每得到一个k, 消去一行
class Solution {
public:
    int index(char c){
        switch(c){
            case 'c': return 0; break;
            case 'r': return 1; break;
            case 'o': return 2; break;
            case 'a': return 3; break;
            case 'k': return 4; break;
            default: return -1;
        }
    }
    int minNumberOfFrogs(string croakOfFrogs) {
        vector<int> count(5, 0);
        int res = 0;
        for(char c: croakOfFrogs){
            int ind = index(c);
            count[ind]++;
            if(ind > 0 and count[ind - 1] < count[ind]){
                return -1;
            }
            if(ind == 4){
                for(int i = 0; i < 5; ++i){
                    count[i]--;
                }
            }
            res = max(res, count[0]);
        }
        if(count[0] != 0){
            return -1;
        }
        else{
            return res;
        }

    }
};
#endif //SRC_COUNTFROGS_1418_H
