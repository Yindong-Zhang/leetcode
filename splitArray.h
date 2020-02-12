//
// Created by so_go on 2020/2/12.
//
/*
 * 给定一个非负整数数组和一个整数 m，你需要将这个数组分成 m 个非空的连续子数组。设计一个算法使得这 m 个子数组各自和的最大值最小。

注意:
数组长度 n 满足以下条件:

    1 ≤ n ≤ 1000
    1 ≤ m ≤ min(50, n)

示例:

输入:
nums = [7,2,5,10,8]
m = 2

输出:
18

解释:
一共有四种方法将nums分割为2个子数组。
其中最好的方式是将其分为[7,2,5] 和 [10,8]，
因为此时这两个子数组各自的和的最大值为18，在所有情况中最小。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/split-array-largest-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#ifndef SRC_SPLITARRAY_H
#define SRC_SPLITARRAY_H

#include<vector>
#include<climits>
using namespace std;
class SplitArray {
public:
    // 对问题递归定义，动态规划进行记忆化搜索。
    /*
    int splitArray(vector<int>& nums, int m) {
        vector<vector<int>> dp(m, vector<int>(nums.size(), 0));
        int tsum = 0;
        for(int i = 0; i < nums.size(); i++){
            tsum += nums[i];
            dp[0][i] = tsum;
        }
        for(int k = 1; k < m; k++){
            for(int i =  k; i < nums.size(); i++){
                int tmin = INT_MAX, psum = 0;
                for(int j = i; j >= k; j--){
                    psum += nums[j];
                    if(tmin > max(dp[k-1][j-1], psum)){
                        tmin = max(dp[k - 1][j - 1], psum);
                    }
                }
                dp[k][i] = tmin;
            }
        }
        return dp[m - 1][nums.size() - 1];
    }
    */

    // 二分法，求最小划分，逆向思维，进行二分搜索
    // 能否将数组分为最大和 >= x 的连续数组
    bool F(int x, vector<int> &nums, int m){
        int psum = 0, cnt = 0;
        for(int i = 0; i < nums.size(); i++){
//            cout << i << ' ' << cnt << endl;
            if(nums[i] > x){
                return false;
            }
            psum += nums[i];
            if(psum > x){
                cnt++;
                psum = nums[i];
            }
            if(cnt > m){
                return false;
            }
        }
        cnt++;
        if(cnt > m){
            return false;
        }
        else{
            return true;

        }
    }


    // 二分搜索
    int splitArray(vector<int>& nums, int m) {
        int nSum = 0, nMax = INT_MIN;
        for(int n : nums){
            nSum += n;
            nMax = max(n, nMax);
        }
        int l = nMax, r = nSum;
        while(l < r){
            cout << l << ' ' << r << endl;
            int mid = (l + r) / 2;
            if(F(mid, nums, m)){
                r = mid;
            }
            else{
                l = mid + 1;
            }

        }
        return l;
    }
};
#endif //SRC_SPLITARRAY_H
