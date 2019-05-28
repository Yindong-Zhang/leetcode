//
// Created by so_go on 2019/5/28.
//

#ifndef SRC_CONTAINDUPLICATES_H
#define SRC_CONTAINDUPLICATES_H
#include<vector>
#include<algorithm>
using namespace std;

class ContainDuplicates {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() == 0){
            return false;
        }
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i - 1] == nums[i]){
                return true;
            }
        }
        return false;
    }
};
#endif //SRC_CONTAINDUPLICATES_H
