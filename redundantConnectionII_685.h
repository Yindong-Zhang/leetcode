//
// Created by so_go on 2020/2/25.
//
/*
 * 在本问题中，有根树指满足以下条件的有向图。该树只有一个根节点，所有其他节点都是该根节点的后继。每一个节点只有一个父节点，除了根节点没有父节点。

输入一个有向图，该图由一个有着N个节点 (节点值不重复1, 2, ..., N) 的树及一条附加的边构成。附加的边的两个顶点包含在1到N中间，这条附加的边不属于树中已存在的边。

结果图是一个以边组成的二维数组。 每一个边 的元素是一对 [u, v]，用以表示有向图中连接顶点 u and v和顶点的边，其中父节点u是子节点v的一个父节点。

返回一条能删除的边，使得剩下的图是有N个节点的有根树。若有多个答案，返回最后出现在给定二维数组的答案。

示例 1:

输入: [[1,2], [1,3], [2,3]]
输出: [2,3]
解释: 给定的有向图如下:
  1
 / \
v   v
2-->3

示例 2:

输入: [[1,2], [2,3], [3,4], [4,1], [1,5]]
输出: [4,1]
解释: 给定的有向图如下:
5 <- 1 -> 2
     ^    |
     |    v
     4 <- 3

注意:

    二维数组大小的在3到1000范围内。
    二维数组中的每个整数在1到N之间，其中 N 是二维数组的大小。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/redundant-connection-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#ifndef SRC_REDUNDANTCONNECTIONII_685_H
#define SRC_REDUNDANTCONNECTIONII_685_H
#include<vector>

class Solution {
public:
    // 未完成
    // 基本思路如下，遍历有向图入度，
    // 如果存在入度为2的节点，删除其中一个入边，确保剩下的节点依然联通
    // 如果所有节点入度为1， 依次删除入边，使节点为根节点，确保剩下的节点依然联通
    // 联通性判断可以通过并查集实现
    // 是否有更好的解法？？？
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int nV = edges.size();
        vector<int> parent(nV, 0);
        for(int i = 0; i < nV; ++i){
            parent[i] = i;
        }
        for(auto &edge: edges){
            if(parent[edge[1] - 1] != edge[1] -1){
                return edge;
            }
            else{
                int root = i;
                while(parent[root] != root){
                    root = parent[root];
                }
                if(edge[0] == root + 1){
                    return edge;
                }
                else{
                    parent[edge[1] - 1] = edge[0] - 1;

                }
            }
        }
        return {0, 0};
    }
};
#endif //SRC_REDUNDANTCONNECTIONII_685_H
