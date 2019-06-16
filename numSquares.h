//
// Created by yindong on 19-6-16.
//

#ifndef SRC_NUMSQUARES_H
#define SRC_NUMSQUARES_H
#include<vector>
#include<cmath>
#include<climits>
using namespace std;

class NumberSquares{
public:
    int numberSquare(int n){
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        int min, sub, j;
        for(int k = 1; k < n + 1; k++){
            min = INT_MAX;
            j = floor(sqrt(k));
            for(int i = 1; i <= j; i++){
                sub = k - pow(i, 2);
                if(dp[sub] < min){
                    min = dp[sub];
                }
            }
            dp[k] = 1 + min;
        }
        return dp[n];

    }
};
#endif //SRC_NUMSQUARES_H
