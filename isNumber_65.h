//
// Created by so_go on 2020/3/16.
//
/*
验证给定的字符串是否可以解释为十进制数字。

例如:

"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
" -90e3   " => true
" 1e" => false
"e3" => false
" 6e-1" => true
" 99e2.5 " => false
"53.5e93" => true
" --6 " => false
"-+3" => false
"95a54e53" => false

说明: 我们有意将问题陈述地比较模糊。在实现代码之前，你应当事先思考所有可能的情况。这里给出一份可能存在于有效十进制数字中的字符列表：

    数字 0-9
    指数 - "e"
    正/负号 - "+"/"-"
    小数点 - "."

当然，在输入中，这些字符的上下文也很重要。

更新于 2015-02-10:

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#ifndef SRC_ISNUMBER_65_H
#define SRC_ISNUMBER_65_H
#include<bits/stdc++.h>
using namespace std;
// 思路是确定有限状态自动机，表驱动法实现，实现很简单
// 没有通过全部样例，我在各种奇怪的反例中迷失了。。。
class IsNumber65 {
public:
    vector<vector<int>> T{{1, 2, -1, -1, 0},
                          {-1, 2, -1, -1, -1},
                          {-1, 2, 3, 4, 7},
                          {-1, 3, -1, 4, 7},
                          {5, 6, -1, -1, 1},
                          {-1, 6, -1, -1, -1},
                          {-1, 6, -1, -1, 7},
                          {-1, -1, -1, -1, 7}};

    int char2Ind(char c){
        if(c == '+' or c == '-'){
            return 0;
        }
        else if( c - '0' >= 0 and c - '0' <= 9){
            return 1;
        }
        else if(c == '.'){
            return 2;
        }
        else if(c == 'e'){
            return 3;
        }
        else if(c == ' '){
            return 4;
        }
        else{
            return -1;
        }
    }

    bool isNumber(string s) {
        int state = 0;
        vector<int> finals{0, 0, 1, 1, 0, 0, 1, 1};
        for(int i = 0; i < s.size(); ++i){
            if(state == -1){
                return false;
            }
            else{
                int charInd = char2Ind(s[i]);
                if(charInd == -1){
                    return false;
                }
                state = T[state][charInd];
            }
        }
        if(state != -1 and finals[state]){
            return true;
        }
        else{
            return false;
        }
    }
};
#endif //SRC_ISNUMBER_65_H
