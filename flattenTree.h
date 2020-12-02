//
// Created by so_go on 2020/7/19.
//
/*
 * 给定一个二叉树，原地将它展开为一个单链表。



例如，给定二叉树

    1
   / \
  2   5
 / \   \
3   4   6

将其展开为：

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#ifndef SRC_FLATTENTREE_H
#define SRC_FLATTENTREE_H
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}

// 理解题意错误，仔细审题
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *l, *r;
        recurFlatten(root, l, r);
        l->left= NULL;
        r->right= NULL;
    }

    void recurFlatten(TreeNode *root, TreeNode *&l, TreeNode *&r){
        if(root == NULL){
            l = NULL;
            r = NULL;
            return;
        }
        TreeNode *ll, *lr, *rl, *rr;
        recurFlatten(root->left, ll, rr);
        recurFlatten(root->right, rl, rr);
        if(ll == NULL){
            l = root;
        }
        else{
            l = ll;
            lr->right = root;
            root->left = lr;
        }
        if(rl == NULL){
            r = root;
        }
        else{
            r = rl;
            root->right= rl;
            rl->left = root;
        }
    }
};
#endif //SRC_FLATTENTREE_H
