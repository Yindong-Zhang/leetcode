//
// Created by yindong on 19-6-18.
//

#ifndef SRC_TOPOLOGICALSORT_H
#define SRC_TOPOLOGICALSORT_H
#include<vector>
#include<queue>
#include"printVector.h"
#include<algorithm>
using namespace std;

class TopologicalSort {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        for(int i = 0; i < prerequisites.size(); i++){
            inDegree[prerequisites[i][0]]++;
        }
        printVector(inDegree);

        queue<int> q;
        vector<bool> visited(numCourses, false);
        int cur, next;
        for(int i = 0; i < inDegree.size(); i++){
            if(inDegree[i] == 0){
                q.push(i);
                visited[i] = true;
            }
        }

        while(not q.empty()){
            cur = q.front();
            q.pop();
            for(int i = 0; i < prerequisites.size(); i++){
                if(prerequisites[i][1] == cur and not visited[prerequisites[i][0]]){
                    printVector(prerequisites[i]);
                    next = prerequisites[i][0];
                    inDegree[next]--;
                    if(inDegree[next] == 0){
                        q.push(next);
                        visited[next] = true;
                    }
                    // next node in degree minus 1
                }

            }
        }

        printVector(visited);
        for(int i = 0; i < numCourses; i++){
            if(not visited[i]){
                return false;
            }

        }
        return true;
    }
};
#endif //SRC_TOPOLOGICALSORT_H
