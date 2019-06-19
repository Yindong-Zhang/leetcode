//
// Created by so_go on 2019/6/19.
//

#ifndef SRC_FRACTION2DECIMAL_H
#define SRC_FRACTION2DECIMAL_H
#include<string>
#include<vector>
#include<set>
#include<map>
#include"printVector.h"
using namespace std;
class Fraction2Decimal {
public:
    /*
     * long long everywhere
     *
     */
    string fractionToDecimal(int numerator, int denominator) {
        long long p = numerator, q = denominator, r, i;
        bool symbol = true;
        if(numerator < 0){
            p = -p;
            symbol = not symbol;
        }
        if(denominator < 0){
            q = -q;
            symbol = not symbol;
        }
        bool isRepeat = false;
        int repeatPos;
        vector<long long> vec;
        int pos = 1;
        map<int, int> rpos;
        do{
            i = p / q;
            vec.push_back(i);
            r = p % q;

            if(rpos.find(r) == rpos.end()){
                rpos.insert({r, pos});
            }
            else{
                isRepeat = true;
                repeatPos = rpos[r];
                break;
            }
            cout << i << ' ' << r << endl;
            p = r * 10;
            pos++;
        }
        while(r != 0);
        printVector(vec);

        string res;
        cout << symbol << ' ' << p << endl;
        if(not symbol and numerator != 0){
            res.push_back('-');
        }
        res.append(to_string(vec[0]));
        if(vec.size() > 1){
            res.push_back('.');
            for(int i = 1; i < vec.size(); i++){
                if(isRepeat and repeatPos == i){
                    res.push_back('(');
                }
                res.append(to_string(vec[i]));
            }
            if(isRepeat){
                res.push_back(')');
            }
        }
        return res;
    }
};
#endif //SRC_FRACTION2DECIMAL_H
