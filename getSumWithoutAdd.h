//
// Created by so_go on 2019/6/23.
//

#ifndef SRC_GETSUMWITHOUTADD_H
#define SRC_GETSUMWITHOUTADD_H

class GetSumWithoutAdd {
public:
    //TODO:
    // 不能处理负值。。。
    /*
    int getSum(int a, int b) {
        if(b == 0){
            return a;
        }
        long long add, carry;
        long long la = a, lb = b;
        while( lb != 0){
            la = la ^ lb;
            lb = (la & lb) << 1;

        }
        return la;
    }
     */

    // 模拟加法，逐位操作。。。
};
#endif //SRC_GETSUMWITHOUTADD_H
