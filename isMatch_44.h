//
// Created by so_go on 2020/3/15.
//

#ifndef SRC_ISMATCH_44_H
#define SRC_ISMATCH_44_H
#include<bits/stdc++.h>
using namespace std;

class IsMatch44 {
public:
    bool isMatch(string s, string p) {
//        return isMatchRecursive(s, p, 0, 0);
        return isMatchDP(s, p);
    }
    /*
     * s= "aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", p = "a*******b"
    果然，线上超时，'*'的情况很容易出现重复子问题
     */
    bool isMatchRecursive(string &s, string &p, int i, int j){
        // 递归截至条件
        if( j == p.size() and i < s.size()){
            return false;
        }
        if( i == s.size() and j == p.size()){
            return true;
        }
        if( i == s.size() and j < p.size()){ // 特殊情况 s = 'abc', p = 'abcd' or 'abc**'
            if(p[j] != '*'){
                return false;
            }
        }
        if(p[j] == '*'){
            for(int k = i; k <= s.size(); ++k){
                if(isMatchRecursive(s, p, k, j + 1)){
                    return true;
                }
            }
        }

        if(p[j] == '?' and i < s.size()){ // 注意数组边界
            return isMatchRecursive(s, p, i + 1, j + 1);
        }
        if(i < s.size() and p[j] == s[i]){
            return isMatchRecursive(s, p, i + 1, j + 1);
        }
        else{
            return false;
        }
    }

    bool isMatchDP(string &s, string &p){
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        dp[0][0] = true;
        for(int j = 1; j <= p.size(); ++j){
            if(p[j - 1] == '*'){
                dp[0][j] = dp[0][j - 1];
            }
            else{
                dp[0][j] = false;
            }
        }
        for(int i = 1; i <= s.size(); ++i){
            dp[i][0] = false;
        }
        // dp[i][j] s[0, i)和 p[0,j)是否匹配
        for(int i = 1; i <= s.size(); ++i){
            for(int j = 1; j <= p.size(); ++j){
                if(s[i - 1] == p[j - 1] or p[j - 1] == '?'){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if(p[j-1] == '*'){
                    dp[i][j] = dp[i - 1][j] or dp[i][j - 1] or dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = false;
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};
#endif //SRC_ISMATCH_44_H
