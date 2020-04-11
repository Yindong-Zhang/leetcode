//
// Created by so_go on 2020/4/9.
//
/*
 * 780. 到达终点

从点 (x, y) 可以转换到 (x, x+y)  或者 (x+y, y)。

给定一个起点 (sx, sy) 和一个终点 (tx, ty)，如果通过一系列的转换可以从起点到达终点，则返回 True ，否则返回 False。

示例:
输入: sx = 1, sy = 1, tx = 3, ty = 5
输出: True
解释:
可以通过以下一系列转换从起点转换到终点：
(1, 1) -> (1, 2)
(1, 2) -> (3, 2)
(3, 2) -> (3, 5)

输入: sx = 1, sy = 1, tx = 2, ty = 2
输出: False

输入: sx = 1, sy = 1, tx = 1, ty = 1
输出: True

注意:

    sx, sy, tx, ty 是范围在 [1, 10^9] 的整数。


 */
#ifndef SRC_REACHPOINTS_780_H
#define SRC_REACHPOINTS_780_H
#include<bits/stdc++.h>
using namespace std;
// 审题， x > 0, y > 0 ,由此可以得到一个重要性质， 对子顶点，其父顶点是唯一的，不存在重复搜索问题，因此可以进行反向回溯, 这是关键
class ReachPoints {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        int mx = tx, my = ty;
        while(mx >= sx and my >= sy){
            if(mx == sx and my == sy){
                return true;
            }
            if(mx >= my){
                if(mx > sx and (mx - sx) % my == 0){
                    mx = sx;
                }
                else{
                    mx = mx % my;
                }
            }
            else{
                if(my > sy and (my - sy) % mx == 0){
                    my = sy;
                }
                else{
                    my = my % mx;
                }
            }
        }
        return false;
    }
};
#endif //SRC_REACHPOINTS_780_H
