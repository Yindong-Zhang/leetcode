//
// Created by so_go on 2019/5/27.
//

#ifndef SRC_FINDWORD2_H
#define SRC_FINDWORD2_H
#include<vector>
#include<string>
#include<array>

using namespace std;
class TrieNode{
public:
    bool is_str;
    bool is_found;
    char ch;
    TrieNode *next[26];

    TrieNode(){
        for(int i = 0; i < 26; ++i){
            next[i] = NULL;
        }
    }
};
class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode root;

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *cur_node_pt = &root;
        char ch;
        int ord;
        TrieNode *new_node_pt;
        for(int i = 0; i < word.size(); ++i){
            ch = word[i];
            ord = ch - 'a';
            if( !cur_node_pt->next[ord] ){
                new_node_pt = new TrieNode();
                new_node_pt->ch = ch;
                new_node_pt->is_str = false;
                cur_node_pt->next[ord] = new_node_pt;
            }
            cur_node_pt = cur_node_pt->next[ord];
        }

        cur_node_pt->is_str = true;
        cur_node_pt->is_found = false;
    }


    /** Returns if the word is in the trie. */
    // 遍历单词，检查当前字母所对应指针是否存在，存在就进到下一个字母和对应节点，不存在则返回失败
    bool search(string word) {
        TrieNode *cur_node = &root;
        int ord;
        for(auto it = word.begin(); it != word.end(); ++it){
            ord = *it - 'a';
            if(cur_node->next[ord]){
                cur_node = cur_node->next[ord];
            }
            else{
                return false;
            }
        }
        if(cur_node->is_str){
            return true;
        }
        else{
            return false;
        }
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    // 检查遍历单词，每个字母是否可达，遍历单词，如果字母所对应的指针存在，则进到下一字母和指针所对应下一节点，直到最后一个字母，否则返回失败；
    bool startsWith(string prefix) {
        TrieNode *cur_node = &root;
        int ord;
        for(auto it = prefix.begin(); it != prefix.end(); ++it){
            ord = *it - 'a';
            if(cur_node->next[ord]){
                cur_node = cur_node->next[ord];
            }
            else{
                return false;
            }
        }
        return true;
    }
};

class FindWord2 {
public:
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    /* 对于网格中的每个字母，判断下一个可能的组合是否存在于前缀树中，不存在就跳过该搜索方向，存在就递归进行下一步搜索 */
        vector<string> results;
        int nrows = board.size(), ncols = board[0].size();
        vector<vector<bool>> visited(nrows, vector<bool>(ncols, false));
        string s;
        char ch;
        Trie trie;
        for(auto it  = words.begin(); it != words.end(); ++it){
            trie.insert(*it);
        }


        for(int i = 0; i < nrows; ++i)
            for(int j = 0; j < ncols; ++j){
                // 初始化 visited 数组
                for(int ix = 0; ix < nrows; ++ix)
                    for(int jx = 0; jx < ncols; ++jx){
                        visited[ix][jx] = false;
                    }
                s.clear();

//                cout << i << ' ' << j << endl;
                ch = board[i][j];
                if(trie.root.next[ch - 'a']) {
                    visited[i][j] = true;
                    s.push_back(ch);
                    dfs(board, trie.root.next[ch - 'a'], s, visited, i, j, results);
                }

            }
        return results;
    }

    void dfs(vector<vector<char>> &board, TrieNode *trie_node, string prefix, vector<vector<bool>> &visited, int i,
             int j, vector<string> &results){
        /* 递归设计初始条件警告， 截止条件，递归过程
         * 对于当前位置(i, j) ，已有单词前缀prefix, 和已访问节点网格visited, 单词列表的前缀树trie, 查找匹配单词
        * 搜索方向 (0, 1) (0, -1), (1, 0) (-1, 0)
         * 判断当前节点是否是单词，如果是，则将当前单词存入结果，
         * 对于每个搜索方向，判断下一字母是否已访问过，未访问则继续，已访问则跳过
        * 判断下一字母在前缀树中对应下一节点是否存在，存在则将下一个字母附在已有单词前缀的末尾，设置已访问位置， 跳至下一节点，位置移到下一个字母，进行下一步搜索
         * 不存在则将字母退栈，恢复已访问位置，搜索下一个方向
         */
        if(trie_node->is_str && !trie_node->is_found){
            results.push_back(prefix);
            trie_node->is_found = true;
//            cout << prefix << endl;
        }
        int nrows = board.size(), ncols = board[0].size();
        int nx_i, nx_j;
        char ch;

        for(int d = 0; d < 4; ++d){
            nx_i = i + dir[d][0];
            nx_j = j + dir[d][1];
            if( 0 <= nx_i  && nx_i < nrows && 0 <= nx_j && nx_j < ncols){
                if( !visited[nx_i][nx_j] ){
                    ch = board[nx_i][nx_j];
                    if(trie_node->next[ ch - 'a' ]){
                        prefix.push_back(ch);
                        visited[nx_i][nx_j] = true;
                        // cout << i << ' '<< j  << "->" << nx_i << ' ' << nx_j << endl;
                        dfs(board, trie_node->next[ch - 'a'], prefix, visited, nx_i, nx_j, results);
                        prefix.pop_back();
                        visited[nx_i][nx_j] = false;
                    }
                }

            }
        }
    }
};
#endif //SRC_FINDWORD2_H
