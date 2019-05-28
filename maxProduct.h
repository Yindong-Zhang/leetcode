//
// Created by so_go on 2019/5/28.
//

#ifndef SRC_MAXPRODUCT_H
#define SRC_MAXPRODUCT_H

#include<vector>
#include<algorithm>
#include<limits>
using namespace std;

class MaxProduct {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> maxm(nums.size(), 0);
        vector<int> minm(nums.size(), 0);
        maxm[0] = nums[0];
        minm[0] = nums[0];
        int a, b;
        for(int i = 1; i < nums.size(); ++i){
//            cout << m[i - 1] << ' ';
            a = maxm[i - 1] * nums[i];
            b = minm[i - 1] * nums[i];

            maxm[i] = max(nums[i], max(a, b));
            minm[i] = min(nums[i], min(a, b));
        }

        int max_prd = maxm[0];
        for(auto it = maxm.begin(); it != maxm.end(); ++it){
            if( *it > max_prd ){
                max_prd = *it;
            }
        }
         return max_prd;
    }
};
#endif //SRC_MAXPRODUCT_H
