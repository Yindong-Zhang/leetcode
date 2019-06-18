//
// Created by so_go on 2019/6/18.
//

#ifndef SRC_SINGLENUMBER_H
#define SRC_SINGLENUMBER_H
#include<vector>
using namespace std;

class SingleNumber {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            res = res ^ nums[i];
        }
        return res;
    }
};
#endif //SRC_SINGLENUMBER_H
