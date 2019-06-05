//
// Created by so_go on 2019/6/5.
//

#ifndef SRC_KTHSMALLESTINBINARYTREE_H
#define SRC_KTHSMALLESTINBINARYTREE_H
//Definition for a binary tree node.
#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class KthSmalledstInBinaryTree {
public:
    // 二叉搜索树中序遍历
    // dfs: 递归搜索第k小的元素
    //
    bool isfind = false;
    int kthSmallest(TreeNode* root, int k) {
        vector<int> numbers;
        dfs(numbers, root, k);
        // cout << "number of vector: " << numbers.size() << endl;
        return numbers.back();
    }


    void dfs(vector<int>& values, TreeNode *node, int k){
        // 递归
        if(not isfind){
            if(node->left ){
                dfs(values, node->left, k);
            }
            if(not isfind){
                cout << node->val << endl;
                values.push_back(node->val);
                if(values.size() == k){
                    isfind = true;
                }
            }


            if(node->right and not isfind){
                dfs(values, node->right, k);
            }
        }


    }
};
#endif //SRC_KTHSMALLESTINBINARYTREE_H
