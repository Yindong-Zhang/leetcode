//
// Created by so_go on 2019/5/28.
//

#ifndef SRC_REVERSESTRING_H
#define SRC_REVERSESTRING_H

#include<vector>
using namespace std;
class ReverseString {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size() - 1;
        char tmp;
        while(i < j){
            tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            i++;
            j--;
        }
    }
};
#endif //SRC_REVERSESTRING_H
