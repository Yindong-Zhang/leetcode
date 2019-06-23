//
// Created by so_go on 2019/6/21.
//

#ifndef SRC_MISSINGNUMBER_H
#define SRC_MISSINGNUMBER_H
#include<vector>
using namespace std;
class MissingNumber {
public:
    int missingNumber(vector<int>& nums) {
        long long origin = nums.size() * (nums.size() + 1) / 2, sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        int res = origin - sum;
        return res;
    }
};
#endif //SRC_MISSINGNUMBER_H
