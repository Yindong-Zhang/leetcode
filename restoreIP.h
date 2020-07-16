//
// Created by so_go on 2020/7/14.
//
/*
 * 93. 复原IP地址

给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

有效的 IP 地址正好由四个整数（每个整数位于 0 到 255 之间组成），整数之间用 '.' 分隔。



示例:

输入: "25525511135"
输出: ["255.255.11.135", "255.255.111.35"]


 */
#ifndef SRC_RESTOREIP_H
#define SRC_RESTOREIP_H


class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<string> tmp;
        int i = 0;
        dfs(s, i, tmp, res);
        return res;
    }

    bool isValid(string &s, int i, int l){
        if(l == 1){
            return true;
        }
        if(l == 2){
            if(s[i] != '0'){
                return true;
            }
        }
        if(l == 3){
            if(s[i] == '1'){
                return true;
            }
            if(s[i] == '2'){
                if(s[i + 1] <= '4'){
                    return true;
                }
                if(s[i + 1] == '5' and s[i + 2] <= '5'){
                    return true;
                }
            }
        }
        return false;
    }

    void dfs(string &s, int i, vector<string> &tmp, vector<string> &res){
        if((4 - tmp.size()) * 3 < s.size() - i){
            return;
        }
        if(tmp.size() == 4){
            if(i == s.size()){
                string ret;
                stringstream ss;
                for(int i = 0; i < 4; ++i){
                    ss << tmp[i];
                    if(i < 3){
                        ss << '.';
                    }

                }
                ss >> ret;
                res.push_back(ret);
            }
            return;
        }
        for(int l = 1; l <= 3 and i + l <= s.size(); l++){
            if(isValid(s, i, l)){
//                cout << "test";
                tmp.push_back(s.substr(i, l));
                dfs(s, i + l, tmp, res);
                tmp.pop_back();
            }
        }

    }



};
#endif //SRC_RESTOREIP_H
