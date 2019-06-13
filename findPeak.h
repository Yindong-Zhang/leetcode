//
// Created by yindong on 19-6-13.
//

#ifndef SRC_FINDPEAK_H
#define SRC_FINDPEAK_H
#include<vector>
using namespace std;

class FindPeak {
public:
    int findPeakElement(vector<int>& nums) {
        return findPeak(nums, 0, nums.size());
    }

    int findPeak(vector<int> &nums, int start, int end){
        // 左闭右开
        // 找到数组中间位置
        // 当中间位置数值小于其左边，则左半边必有峰值
        // 当中间位置值小于其右边，则右半边必有峰值
        // 否则，中间位置即为峰值
        // 当数组长度为１，返回
        if( end - start == 1){
            return start;
        }
        int mid = (end + start) / 2;
        cout << start << ' ' <<  mid << ' ' << end << endl;
        // 数组边界检查！！！
        if(mid + 1 < nums.size() and nums[mid] < nums[mid + 1]){
            return findPeak(nums, mid + 1, end);
        }
        else if(nums[mid] < nums[mid - 1]){
            return findPeak(nums, start, mid);
        }
        else{
            return mid;
        }
    }
};
#endif //SRC_FINDPEAK_H
