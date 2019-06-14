//
// Created by so_go on 2019/6/14.
//

#ifndef SRC_KREPEATEDLONGESTSUBSTRING_H
#define SRC_KREPEATEDLONGESTSUBSTRING_H
#include"printVector.h"
#include<string>
#include<vector>
#include<array>
using namespace std;

class KRepeatedLongestSubstring {
public:
    int longestSubstring(string s, int k) {
        return partition(s, 0, s.size(), k);

    }

    int partition(string &s, int i, int j, int k){
        /* 遍历计数，对于重复次数小于k的字符，在对应位置分割，
         * 对分割得到的所有子串，重复以上操作，取所有分割子串返回值的最大值，
         * 若重复次数均大于k，无需再次分割，返回子串长度
         *
         * 在s[i, j)中搜索
         *
         * 若 j - i < k 则返回0
         */
        //截止条件
        cout << i << ' ' << j << endl;
        if( j - i < k ){
            return 0;
        }
        vector<int> count(26, 0);
        for(int it = i; it < j; it++){
            count[s[it] - 'a']++;
        }
        printVector(count);
        // 截止2
        bool flag = true;
        for(int c: count){
            if(c < k and c > 0){
                flag = false;
                break;
            }
        }

        if(flag){
            return j - i;
        }
        else{
            //遍历字符串，寻找下一分割点
            int last_cut = i;
            int max = 0, tmp;
            for(int it = i; it < j; it++){
                if(count[s[it] - 'a'] < k){
                    tmp = partition(s, last_cut, it, k);
                    if(tmp > max){
                        max = tmp;
                    }
                    last_cut = it + 1;
                }
            }
            if(last_cut != j){
                tmp = partition(s, last_cut, j, k);
                if(tmp > max){
                    max = tmp;
                }
            }
            return max;
        }
    }
};
#endif //SRC_KREPEATEDLONGESTSUBSTRING_H
