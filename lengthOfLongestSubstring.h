//
// Created by so_go on 2019/5/31.
//

#ifndef SRC_LENGTHOFLONGESTSUBSTRING_H
#define SRC_LENGTHOFLONGESTSUBSTRING_H
#include<string>
using namespace std;
class LengthOfLongestSubstring {
public:
    int lengthOfLongestSubstring(string s) {
        /*保存每个位置以当前字母结尾的最长字串，以此更新下一位置的最长字串
         * 对于当前字母，遍历子串，如果不存在于前一子串，子串不变
         * 如果遇到该字母，截取字串，
         * 将当前字母拼接在结尾。
         * 遍历字符串，保存最长字串长度。
         */
        string sub;
        int max_len = 0;
        for(char ch : s){
            for(int i = 0; i < sub.size(); i++){
                if(sub[i] == ch){
                    sub = sub.substr(i + 1, sub.size() - i - 1);
                }
            }
            sub.push_back(ch);
            cout << sub << endl;
            if( sub.size() > max_len){
                max_len = sub.size();
            }
        }
        return max_len;


    }
};
#endif //SRC_LENGTHOFLONGESTSUBSTRING_H
