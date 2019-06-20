//
// Created by so_go on 2019/6/20.
//

#ifndef SRC_HAMMINGWEIGHT_H
#define SRC_HAMMINGWEIGHT_H
#include<cstdint>
using namespace std;

class HammingWeight {
public:
    int hammingWeight(uint32_t n) {
        uint32_t res = 0, r;
        for(int i = 0; i < 32; i++){
            r = n % 2;
            res += r;
            n = n / 2;
        }
        return res;
    }
};
#endif //SRC_HAMMINGWEIGHT_H
