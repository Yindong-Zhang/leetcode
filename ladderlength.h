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
#include<unordered_set>
using namespace std;
class LadderLength {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int num_nodes = wordList.size() + 1;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if(wordSet.find(endWord) == wordSet.end()){
            cout << "End word not found." << endl;
            return 0;
        }

        return bfs(beginWord, endWord, wordSet);
    }

    struct Record{
        string str;
        int depth;
    };

    int bfs(string initial, string target, unordered_set<string> wordSet){
        queue<Record> q;
        // initial
        q.push(Record{initial, 1});

        string alphebet = "abcdefghijklmnopqrstuvwxyz";
        Record cur;
        string newStr;
        while(not q.empty()){
            cur = q.front();
            q.pop();
            cout << cur.str << ' ' << cur.depth << endl;
            if(cur.str == target){
                return cur.depth;
            }
            for(int i = 0; i < cur.str.size(); i++){
                for(int j = 0; j < 26; j++) {
                    newStr = cur.str;
                    newStr[i] = alphebet[j];
                    auto newStr_ptr = wordSet.find(newStr);
                    if(newStr_ptr != wordSet.end()){
                        q.push({newStr, cur.depth + 1});
                        wordSet.erase(newStr_ptr);
                    }
                }
            }
        }
        return 0;
    }

};
#endif //SRC_LADDERLENGTH_H
