//
// Created by so_go on 2020/2/24.
//

#ifndef SRC_UNIONSET_H
#define SRC_UNIONSET_H
#include<vector>
using namespace std;

class UnionFindSet{
public:
    vector<int> parent;
    UnionFindSet(int n){
        for(int i = 0; i < n; i++){
            parent.push_back(i);
        }
    }

    /*
     * 一个写法
    int find(int i){
        int root= i;
        while(parent[root] != root){
            root= parent[root];
        }
        // 路劲压缩
        int cur= i, tmp;
        while(cur != root){
            tmp = parent[cur];
            parent[cur]= root;
            cur= tmp;
        }
        return root;
    }
    */

    // 递归写法：
    int find(int i){
        // 对于当前节点，查找根节点，并返回
        if(parent[i] != i){
            parent[i] = find(parent[i]); // 路径压缩在find不断上溯的过程中完成
        }
        return parent[i]
    }

    // 或者
    /*
    int find(int i){
        if(parent[i] == i){
            return i;
        }
        pre[x] = find(pre[x]);
        return pre[x];
    }
     */

    int join(int i, int j){
        int rti= find(i);
        int rtj = find(j);
        if(rti != rtj){
            parent[rti] = rtj;
        }
    }
};



#endif //SRC_UNIONSET_H
