//
// Created by so_go on 2019/6/20.
//

#ifndef SRC_FACTORIALTRAILINGZERO_H
#define SRC_FACTORIALTRAILINGZERO_H
using namespace std;
class TrailingZero {
public:
    int trailingZeroes(int n) {
        return f(n);
    }

    int f(int n){
        int n_st;
        if(n < 5){
            return 0;
        }
        else{
            n_st = n / 5;
            return n_st + f(n_st);
        }
    }
};
#endif //SRC_FACTORIALTRAILINGZERO_H
