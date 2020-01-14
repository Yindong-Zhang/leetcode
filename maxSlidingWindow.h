//
// Created by so_go on 2019/5/31.
//

#ifndef SRC_MAXSLIDINGWINDOW_H
#define SRC_MAXSLIDINGWINDOW_H
#include<vector>
#include<deque>
using namespace std;
class MaxSlidingWindow {
public:

    // 空间复杂度O(kn), 时间复杂度O(kn), 不是一种好的解法。
    /*
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
     */

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        for(int i = 0; i < nums.size(); i++){
//            for(auto i : dq){
//                cout << i << ' ';
//            }
//            cout << " -> ";
            if(dq.front() == i - k){
                dq.pop_front();
            }
            while(not dq.empty() and nums[i] > nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
//            for(auto i : dq){
//                cout << i << ' ';
//            }
//            cout << endl;
            if(i >= k - 1){
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};
#endif //SRC_MAXSLIDINGWINDOW_H
