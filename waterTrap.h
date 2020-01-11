//
// Created by so_go on 2020/1/11.
//
/*
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。

示例:

输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6

在真实的面试中遇到过这道题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/trapping-rain-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#ifndef SRC_WATERTRAP_H
#define SRC_WATERTRAP_H
#include<vector>
#include<climits>
using namespace std;
class WaterTrap {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0){
            return 0;
        }
       int res = 0, li = 0;
       while( li != height.size() - 1){
           int rmax = INT_MIN, ri;
           for(int j = li + 1; j < height.size(); j++){
               if(height[j] >= height[li]){
                   ri = j;
                   break;
               }
               else{
                   if(height[j] > rmax){
                       rmax = height[j];
                       ri = j;
                   }
               }
           }
           int th = min(height[li], height[ri]);
           for(int k = li + 1; k < ri; k++){
               res += th - height[k];
//               cout << k << ' ' <<  height[k] << ' ' << res << endl;
           }
           li = ri;
       }
       return res;
    }
};
#endif //SRC_WATERTRAP_H
