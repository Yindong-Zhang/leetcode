//
// Created by so_go on 2019/5/27.
//

#ifndef SRC_TRIE_H
#define SRC_TRIE_H

#include<iostream>
using namespace std;
class TrieNode{
public:
    bool is_str;
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
#endif //SRC_TRIE_H
