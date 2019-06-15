//
// Created by yindong on 19-6-15.
//

#ifndef SRC_MAXPATHSUMINBINARYTREE_H
#define SRC_MAXPATHSUMINBINARYTREE_H

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Record{
    int R;
    int q;
};
class MaxPathSumInBinaryTree {
public:
    int maxPathSum(TreeNode* root) {

    }

    // TODO
    Record maxSubTree(TreeNode* root){
        // 当遇到叶节点， R = q = left->value
        if(not root->left and not root->right){
            return Record{root->value, root->value};
        }
        // 非叶节点，注意左右子数有一个为空的情况
        if(root->left){
            auto left = maxSubTree(root->left);
        }
        if(root->right){
            auto right = maxSubTree(root->right);
        }
        int q = root->value;
        if(root->left){
            if( root->value + left.q)
        }
    }
};
#endif //SRC_MAXPATHSUMINBINARYTREE_H
