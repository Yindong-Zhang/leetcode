//
// Created by so_go on 2019/5/29.
//

#ifndef SRC_INCREASINGTRIPLET_H
#define SRC_INCREASINGTRIPLET_H
#include<vector>
#include<limits>
#include<algorithm>
using namespace std;

class IncreasingTriplet {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() == 0){
            return false;
        }
        vector<int> x1(nums.size(), 0), x2(nums.size(), 0), x3(nums.size(), 0);
        x1[0] = nums[0];
        x2[0] = numeric_limits<int>::max();
        for(int i = 1; i < nums.size(); ++i){
            x1[i] = min(x1[i - 1], nums[i]);
            x2[i] = nums[i] > x1[i - 1] ? min(x2[i - 1], nums[i]) : x2[i - 1];
            if(nums[i] > x2[i - 1]){
                return true;
            }
        }
        return false;
    }
};
#endif //SRC_INCREASINGTRIPLET_H
