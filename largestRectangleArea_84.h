//
// Created by so_go on 2020/2/13.
//
/*
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。



以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。



图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。



示例:

输入: [2,1,5,6,2,3]
输出: 10

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-rectangle-in-histogram
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#ifndef SRC_LARGESTRECTANGLEAREA_84_H
#define SRC_LARGESTRECTANGLEAREA_84_H
#include<climits>
#include<vector>
#include<stack>
using namespace std;
// 解题思想类似于leetcode 907 sumSubarrayMins
class LargestRectangleArea {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st_l, st_r;
        vector<int> l(heights.size(), 0), r(heights.size(), 0);
        for(int i = 0; i < heights.size(); i++){
            while(not st_l.empty() and heights[st_l.top()] > heights[i]){
                st_l.pop();
            }
            if(not st_l.empty()){
                l[i] = st_l.top() + 1;
            }
            else{
                l[i] = 0;
            }
            st_l.push(i);
        }

        for(int j = heights.size() - 1; j >= 0; j--){
            while(not st_r.empty() and heights[st_r.top()] > heights[j]){
                st_r.pop();
            }
            if(not st_r.empty()){
                r[j] = st_r.top() - 1;
            }
            else{
                r[j] = heights.size() - 1;
            }
            st_r.push(j);
        }
        int res = INT_MIN;
        for(int i = 0; i < heights.size(); i++){
            res = max(res, heights[i] * (r[i] - l[i] + 1));
        }
        return res;
    }
};
#endif //SRC_LARGESTRECTANGLEAREA_84_H
