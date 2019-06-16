//
// Created by so_go on 2019/6/16.
//

#ifndef SRC_LENGTHOFLIS_H
#define SRC_LENGTHOFLIS_H
#include<vector>
using namespace std;

class LengthOfLIS {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        int max = 0;
        for(int i = 0; i < nums.size(); i++){
            max = 0;
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i] and dp[j] > max){
                    max = dp[j];
                }
            }
            dp[i] = max + 1;
        }
        int longest = 0;
        for(int i = 0; i < nums.size(); i++){
            if(dp[i] > longest){
                longest = dp[i];
            }
        }
        return longest;
    }
};

#endif //SRC_LENGTHOFLIS_H
