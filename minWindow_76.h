//
// Created by so_go on 2020/2/12.
//
/*
 * 给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。

示例：

输入: S = "ADOBECODEBANC", T = "ABC"
输出: "BANC"

说明：

    如果 S 中不存这样的子串，则返回空字符串 ""。
    如果 S 中存在这样的子串，我们保证它是唯一的答案。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-window-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#ifndef SRC_MINWINDOW_76_H
#define SRC_MINWINDOW_76_H

#include<vector>
#include<string>
#include<climits>
#include<map>
using namespace std;

class MinWindow {
public:
    // 字符串T中可能有重复，下面的算法无法通过样例 (aa, aa),
    // 考虑答案所用的滑窗法
    /*
     * 用左右两个指针维护一个窗口。

    将右指针右移，直至窗口满足条件或有变化。
    将左指针左移，直至窗口不再满足条件。记录复合条件的最小子串。
    重复1、2两步。
     */
    string minWindow(string s, string t){
        map<char, int> t_cntr, ch_cntr;
        for(char ch : t){
            if(t_cntr.find(ch) == t_cntr.end()){
                t_cntr[ch] = 1;
                ch_cntr[ch] = 0;
            }
            else{
                t_cntr[ch]++;
            }
        }
        int num_ch = t_cntr.size();
        int l = 0, r = 0, ch_cnt = 0;
        int min_width = INT_MAX;
        string res;
        while(r < s.size()){
            while(r < s.size() and ch_cnt < num_ch){
                char ch = s[r];
                r++;
                if(ch_cntr.find(ch) != ch_cntr.end()){
                    ch_cntr[ch]++;
                    if(ch_cntr[ch] == t_cntr[ch]){
                        ch_cnt++;
                    }
                }
            }
            while(ch_cnt == num_ch){
                char ch = s[l];
                if(ch_cntr.find(ch) != ch_cntr.end()) {
                    ch_cntr[ch]--;
                    if (ch_cntr[ch] < t_cntr[ch]) {
                        ch_cnt--;
                        if(r - l < min_width) {
                            min_width = r - l;
                            res = s.substr(l, r - l);
                        }
                    }
                }
                l++;
            }
        }
        return res;
    }
    // 若字符串T为集合，理论上下面的算法有效且时间效率更高
    /*
    string minWindow(string s, string t) {
        map<char, int> pos;
        for(char c: t){
            pos[c] = -1;
        }
        int i = 0, count = 0;
        while(i < s.size() and pos.find(s[i]) == pos.end()){
            i++;
        }
        if(i < s.size()){
            pos[s[i]] = i;
            char ch_l = s[i];
            count++;
            i++;


            while(i < s.size() and count < pos.size()) {
                if (pos.find(s[i]) != pos.end()) {
                    if (pos[s[i]] == -1) {
                        count++;
                    }
                    pos[s[i]] = i;
                    if (s[i] == ch_l) {
                        int pMin = INT_MAX;
                        for (auto pair: pos) {
                            if (pair.second < pMin) {
                                pMin = pair.second;
                                ch_l = pair.first;
                            }
                        }
                    }
                }
                cout << i << ' ' << count << endl;
                i++;
            }
            int minLen = 0, iBegin= 0;
            if(count == pos.size()){
                minLen = i - pos[ch_l];
                iBegin = pos[ch_l];
            }
            else{
                return "";
            }
            while(i < s.size()){
                if(pos.find(s[i]) != pos.end()){
                    pos[s[i]] = i;
                    if(s[i] == ch_l){
                        int pMin = INT_MAX;
                        for(auto pair: pos){
                            if(pair.second < pMin){
                                pMin = pair.second;
                                ch_l = pair.first;
                            }
                        }
                        if(minLen > i - pMin + 1){
                            minLen = i - pMin + 1;
                            iBegin= pMin;
                        }
                    }
                }
                i++;
            }
            return s.substr(iBegin, minLen);
        }
        else{
            return "";
        }
    }
     */
};
#endif //SRC_MINWINDOW_76_H
