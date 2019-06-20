//
// Created by so_go on 2019/6/20.
//

#ifndef SRC_REVERSEBITS_H
#define SRC_REVERSEBITS_H
#include<cstdint>
class ReverseBits {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0, r;
        for(int i = 0; i < 32; i++){
            r = n % 2;
            r = r << (31 - i);
//            cout << r << endl;
            res += r;

            n = n / 2;
        }
        return res;
    }
};
#endif //SRC_REVERSEBITS_H
