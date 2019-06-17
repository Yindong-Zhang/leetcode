//
// Created by so_go on 2019/6/17.
//

#ifndef SRC_LADDERLENGTH_H
#define SRC_LADDERLENGTH_H
#include<string>
#include<vector>
#include<climits>
#include"printMatrix.h"
#include<queue>
using namespace std;
class LadderLength {
public:
    // 超时。。。。
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int num_nodes = wordList.size() + 1;
        vector<vector<int>> adj_list(num_nodes, vector<int>{});

        int ei = -1;
        bool e_find = false;
        int i = 0;
        while(i < wordList.size() and not e_find){
            if(wordList[i] == endWord){
                ei = i;
                e_find = true;
            }
            i++;
        }

        cout << ei << ' ' << e_find << endl;
        if(not e_find){
            return 0;
        }

        wordList.push_back(beginWord);
        // 构造邻接表
        for(int i = 0; i < num_nodes; i++){
            for(int j = i + 1; j < num_nodes; j++){
                if(isVicinity(wordList[i], wordList[j])){
                    // adj_list[i] append j, adj_list[j] append i
                    adj_list[i].push_back(j);
                    adj_list[j].push_back(i);

                }
            }
        }
        printMatrix(adj_list);
        return bfs(num_nodes - 1, ei, adj_list);
    }

    bool isVicinity(string a, string b){
        int count = 0;
        // 单词长度相同， 单词各不相同
        for(int i = 0; i < a.size(); i++){
            // 出现两个字符不同，判断不符合
            if( a[i] != b[i]){
                count++;
            }
            if( count > 1){
                break;
            }
        }
        if(count == 1){
            return true;
        }
        else{
            return false;
        }
    }
    struct Record{
        int node;
        int depth;
    };

    int bfs(int initial, int target, vector<vector<int>> adj_list){
        queue<Record> q;
        vector<bool> visited(adj_list.size(), false);
        q.push(Record{initial, 1});
        Record cur;
        while(not q.empty()){
            cur = q.front();
            q.pop();
            cout << cur.node << ' ' << cur.depth << endl;
            visited[cur.node] = true;
            if(cur.node == target){
                return cur.depth;
            }
            for(auto ptr = adj_list[cur.node].begin(); ptr != adj_list[cur.node].end(); ptr++){
                if(not visited[*ptr]){
                    q.push(Record{*ptr, cur.depth + 1});
                }
            }
        }
        return -1;
    }

};
#endif //SRC_LADDERLENGTH_H
