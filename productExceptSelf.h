//
// Created by so_go on 2019/5/29.
//

#ifndef SRC_PRODUCTEXCEPTSELF_H
#define SRC_PRODUCTEXCEPTSELF_H
#include<vector>
using namespace std;
class ProductExceptSelf {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> lp(nums.size(), 0), rp(nums.size(), 0);
        vector<int> res(nums.size(), 0);
        int lp_tmp = 1, rp_tmp = 1;
        for(int i = 0; i <nums.size(); ++i){
            lp_tmp *= nums[i];
            lp[i] = lp_tmp;
        }
        for(int i = nums.size() - 1; i >= 0; --i){
            rp_tmp *= nums[i];
            rp[i] = rp_tmp;
        }
        res[0] = rp[1];
        for(int i = 1; i < nums.size() - 1; ++i){
            res[i] = lp[i - 1] * rp[ i + 1];
        }
        res[nums.size() - 1] = lp[nums.size() - 2];
        return res;
    }
};
#endif //SRC_PRODUCTEXCEPTSELF_H
