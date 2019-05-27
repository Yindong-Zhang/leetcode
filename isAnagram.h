//
// Created by so_go on 2019/5/27.
//

#ifndef SRC_ISANAGRAM_H
#define SRC_ISANAGRAM_H
#include<string>
#include<array>
using namespace std;
class IsAnaGram{
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        array<int, 26> isapr_s{0, };
        array<int, 26> isapr_t{0, };
        for(auto ch : s){
            isapr_s[ch - 'a'] += 1;
        }
        for(auto ch : t){
            isapr_t[ch - 'a'] += 1;
        }
        for(int i = 0; i < 26; ++i){
            if(isapr_s[i] != isapr_t[i]){
                return false;
            }
        }
        return true;
    }
};
#endif //SRC_ISANAGRAM_H
