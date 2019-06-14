//
// Created by so_go on 2019/6/14.
//

#ifndef SRC_FINDDUPLICATE_H
#define SRC_FINDDUPLICATE_H

#include<vector>
using namespace std;

class FindDuplicate {
public:
    int findDuplicate(vector<int>& nums) {
        // 选择[m, n)中的一个中间数字l，若[m, l)中的数字数目大于 l - m ，则重复数字必在[m, l)中，反之，则重复数字在[l, n)
        // nums.size() == n + 1, last = n + 1
        return binarySearch(nums, 1, nums.size());
    }

    int binarySearch(vector<int> &nums, int m, int n){
        /*备选区间[m, n)
         * 截止条件： 当 n -m = 1, 返回m
        * 选择中间数字 l = m + n /2, 统计[m, l)中的数字数目count，
         * 当count > l - m 则， 在[m, l)中继续搜索
         * 否则，搜索[l, n)
         */
//        cout << m << ' ' << n << endl;
        if( n - m == 1){
            return m;
        }
        int l = (m + n) / 2;
        int res = -1;
        int count = 0;
        for(auto ptr = nums.begin(); ptr != nums.end(); ptr++){
            if( *ptr >= m and *ptr < l){
                count++;
            }
        }
        if(count > l - m){
            res = binarySearch(nums, m, l);
        }
        else{
            res = binarySearch(nums, l, n);
        }
        return res;
    }
};
#endif //SRC_FINDDUPLICATE_H
