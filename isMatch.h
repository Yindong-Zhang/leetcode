//
// Created by so_go on 2020/2/6.
//
/*
 * 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素

所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

说明:

    s 可能为空，且只包含从 a-z 的小写字母。
    p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。

示例 1:

输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。

示例 2:

输入:
s = "aa"
p = "a*"
输出: true
解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。

示例 3:

输入:
s = "ab"
p = ".*"
输出: true
解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。

示例 4:

输入:
s = "aab"
p = "c*a*b"
输出: true
解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。

示例 5:

输入:
s = "mississippi"
p = "mis*is*p*."
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/regular-expression-matching
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#ifndef SRC_ISMATCH_H
#define SRC_ISMATCH_H
#include<string>
#include<vector>
using namespace std;

class IsMatch {
public:
    bool isMatch(string s, string p) {
        return isMatchDP(s, p);
    }
    // 递归求解，线下可行，线上堆溢出
    // 存在最优子结构，并且存在子问题重复，(dfs 搜索重复？），考虑dp/记忆化搜索
    /*
    bool isMatchRecursive(string &s, string &p, int is, int ip) {
        if (ip == p.size()){
            if (is == s.size()) {
                return true;
            } else {
                return false;
            }
        }
        if(ip + 1 < p.size() and p[ip + 1] == '*'){
            if(is < s.size() and match(s[is], p[ip])){
                return (isMatchRecursive(s, p, is + 1, ip) or isMatchRecursive(s, p, is, ip + 2));
            }
            else{
                return isMatchRecursive(s, p, is, ip + 2);
            }
        }
        else{
            if(match(s[is], p[ip])){
                return isMatchRecursive(s, p, is + 1, ip + 1);
            }
            else{
                return false;
            }
        }
    }
     */
    bool match(char c, char p){
        if(p == '.'){
            return true;
        }
        else if(c == p){
            return true;
        }
        else{
            return false;
        }
    }

    // dp[i][j] s[:i] and p[:j]是否匹配
    bool isMatchDP(string s, string p){
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, 0));
        dp[0][0] = true;
        for(int i = 0; i < s.size() + 1; i++){
            for(int j = 1; j < p.size() + 1; j++){
                if(p[j] == '*'){
                    continue;
                }
                if(p[j - 1] == '*'){
                    if(i == 0){
                        dp[i][j] = dp[i][j - 2];
                    }
                    else{
                        dp[i][j] = dp[i][j - 2] or (match(s[i - 1], p[j - 2]) and (dp[i - 1][j - 2] or dp[i - 1][j]));

                    }
                }
                else{
                    if(i > 0){
                        dp[i][j] = match(s[i - 1], p[j - 1]) and dp[i - 1][j - 1];

                    }
                }
            }
        }
        return dp[s.size()][p.size()];
    }

};
#endif //SRC_ISMATCH_H
