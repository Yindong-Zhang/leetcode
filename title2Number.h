//
// Created by so_go on 2019/6/5.
//

#ifndef SRC_TITLE2NUMBER_H
#define SRC_TITLE2NUMBER_H
#include<string>
using namespace std;

class Title2Number {
public:
    int titleToNumber(string s) {
        int base = 1;
        auto ptr = s.rbegin();
        int res = *ptr - 'A' + 1;
        for(ptr++; ptr != s.rend(); ptr++){
            base *= 26;
            res += (*ptr - 'A' + 1) * base;
        }
        return res;
    }
};
#endif //SRC_TITLE2NUMBER_H
