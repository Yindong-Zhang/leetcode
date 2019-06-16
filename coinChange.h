//
// Created by so_go on 2019/6/16.
//

#ifndef SRC_COINCHANGE_H
#define SRC_COINCHANGE_H

#include<vector>
#include<climits>
using namespace std;
class CoinChange {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 0;
        int min = INT_MAX;
        for(int n = 1; n <= amount; n++){
            min = INT_MAX;
            for(int i = 0; i < coins.size(); i++){
                if( n - coins[i] >= 0 and dp[n - coins[i]] != INT_MAX){
                    if(dp[n - coins[i]] < min){
                        min = dp[n - coins[i]];
                    }
                }
            }
            if(min == INT_MAX){
                dp[n] = INT_MAX;
            }
            else{
                dp[n] = min + 1;
            }
        }
        if(dp[amount] == INT_MAX){
            return -1;
        }
        else{
            return dp[amount];
        }
    }
};
#endif //SRC_COINCHANGE_H
