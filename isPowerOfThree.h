//
// Created by so_go on 2019/6/21.
//

#ifndef SRC_ISPOWEROFTHREE_H
#define SRC_ISPOWEROFTHREE_H

class IsPowerOfThree {
public:
    bool isPowerOfThree(int n) {
        int r = n % 3, n_st = n / 3;
        if(n == 0){
            return false;
        }
        if(n == 1){
            return true;
        }
        if( r == 0){
            return isPowerOfThree(n_st);
        }
        else{
            return false;
        }
    }
};
#endif //SRC_ISPOWEROFTHREE_H
