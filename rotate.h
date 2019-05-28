//
// Created by so_go on 2019/5/28.
//

#ifndef SRC_ROTATE_H
#define SRC_ROTATE_H
#include<vector>
#include<algorithm>
using namespace std;

class Rotate {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }

};
#endif //SRC_ROTATE_H
