//
// Created by so_go on 2020/2/27.
//
/*
 * 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0

示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#ifndef SRC_MEDIANINTWOSORTEDARRAY_H
#define SRC_MEDIANINTWOSORTEDARRAY_H
#include<vector>
using namespace std;

class MedianInTwoSortedArray {
public:
    /* 事实证明，在这道题目中，对特殊情况进行先行处理非常麻烦，需要多次分类讨论
     * 不得不说，对算法进行进一步抽象之后就简单多了，全看你的理解。。。
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int m = nums1.size(), n = nums2.size();
        if(m > n){
            return findMedianSortedArrays(nums2, nums1); // 前提是引用传递
        }
        if(nums2[(m + n - 1) / 2] <= nums1[0]){
            if(( m + n ) % 2 == 0){
                return (nums2[(m + n - 1) / 2] + min(nums1[0], nums2[(m + n + 1) / 2])) / 2.;
            }
            else{
                return nums2[(m + n - 1) / 2];
            }
        }
        if(nums1[m - 1] <= nums2[(n - m + 1)/2]){
            if((m + n) % 2 == 0){
                return (max(nums1[m - 1], nums2[(n - m - 1) / 2]) + nums2[(n - m + 1)/2]) / 2.;
            }
            else{
                return max(nums1[m - 1], nums2[(n - m -1)/2]);
            }
        }
        
        int l = 1, r = m - 1, mid, p= -1; // [l, r]
        while(l < r){
            mid = (l + r) / 2;
            int j_mid = (m + n + 1) / 2 - mid;
            if(nums1[mid - 1] <= nums2[j_mid] and nums2[j_mid - 1] <= nums1[mid]){
                p = mid;
                break;
            }
            else if(nums1[mid - 1] > nums2[j_mid]){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        if(p == -1){
            p = l;
        }
        int j_p = (m + n + 1) / 2 - p;
        if((m + n) % 2 == 0){
            return (max(nums1[p - 1], nums2[j_p - 1]) + min(nums1[p], nums2[j_p])) / 2.;
        }
        else{
            return max(nums1[p - 1], nums2[j_p - 1]);
        }
        // 假定 m < n
        */

        // 待完善
        

    }
};
#endif //SRC_MEDIANINTWOSORTEDARRAY_H
