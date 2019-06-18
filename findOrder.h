//
// Created by so_go on 2019/6/18.
//

#ifndef SRC_FINDORDER_H
#define SRC_FINDORDER_H
#include<vector>
#include"printVector.h"
#include<iostream>
using namespace std;
class FindOrder{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // 深度搜索拓扑排序
        vector<int> inDegree(numCourses, 0);
        for(int i = 0; i < prerequisites.size(); i++){
            inDegree[prerequisites[i][0]]++;
        }
        printVector(inDegree);

        vector<bool> visited(numCourses, false);
        vector<int> order;
        for(int i = 0; i < inDegree.size(); i++){
            if(inDegree[i] == 0 and not visited[i]){
                dfs(i, inDegree, visited, prerequisites, order);
            }
        }

        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] > 0){
                return vector<int>{};
            }
        }

        return order;
    }

    void dfs(int node, vector<int> &inDegree, vector<bool> &visited, vector<vector<int>> &edgelist, vector<int> &order){
        int next;
        order.push_back(node);
        visited[node] = true;
        for(int i = 0; i < edgelist.size(); i++){
            if(edgelist[i][1] == node){
                next = edgelist[i][0];
                inDegree[next]--;
                cout << next << ' ' << inDegree[next] << endl;
                if(inDegree[next] == 0){
                    dfs(next, inDegree, visited, edgelist, order);
                }
            }
        }
    }
};
#endif //SRC_FINDORDER_H
