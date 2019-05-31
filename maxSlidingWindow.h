//
// Created by so_go on 2019/5/31.
//

#ifndef SRC_MAXSLIDINGWINDOW_H
#define SRC_MAXSLIDINGWINDOW_H
#include<vector>
using namespace std;
class MaxSlidingWindow {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size() == 0){
            return vector<int>();
        }
        vector<vector<int>> dp(k, vector<int>(nums.size(), 0));
        dp[0] = nums;
        for(int ki = 1; ki < k; ki++){
            for(int i = 1; i < nums.size(); i++){
                dp[ki][i] = max(dp[ki - 1][i - 1], nums[i]);
            }
        }
        return vector<int>(dp[k - 1].begin() + k - 1, dp[k - 1].end());
    }
};
#endif //SRC_MAXSLIDINGWINDOW_H
