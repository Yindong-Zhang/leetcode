//
// Created by yindong on 19-6-15.
//

#ifndef SRC_MAXPATHSUMINBINARYTREE_H
#define SRC_MAXPATHSUMINBINARYTREE_H
#include<algorithm>
#include<queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *buildTree(vector<string> vec){
    /* vec 中至少有一个数
     * # 代表空指针
     * i 记录 在vec中 的位置，队列 q 记录尚未添加子树的节点
     * 重复：
     * i < size of vector:
     * 将当前位置 i 非空，链接到队首节点的左子树，节点入队
     * i++
     * 如果 i < sizeof vector , 将当前数字非空， 链接到队首节点右子树，节点入队
     * i++
     *
     * 返回根节点
     */
    queue<TreeNode *> q;
    TreeNode *root = new TreeNode(stoi(vec[0]));
    q.push(root);
    int i = 1;
    TreeNode *newNode, *curNode;
    int tmp_val;
    while( i < vec.size()){
        curNode = q.front();
        q.pop();
        if(vec[i] != "#"){
            tmp_val = stoi(vec[i]);
            newNode = new TreeNode(tmp_val);
            curNode->left = newNode;
            q.push(newNode);

        }
        i++;

        if( i < vec.size()){
            if(vec[i] != "#"){
                tmp_val = stoi(vec[i]);
                newNode = new TreeNode(tmp_val);
                curNode->right = newNode;
                q.push(newNode);
            }
            i++;
        }
    }
    return root;
}

struct Record{
    int R;
    int q;
};
class MaxPathSumInBinaryTree {
public:
    int maxPathSum(TreeNode* root) {
        auto res = maxSubTree(root);
        return res.R;
    }

    Record maxSubTree(TreeNode* root){
        // 当遇到叶节点， R = q = left->value
        if(not root->left and not root->right){
            return Record{root->val, root->val};
        }
        // 非叶节点，注意左右子数有一个为空的情况
        Record left, right;
        if(root->left){
            left = maxSubTree(root->left);
        }
        if(root->right){
            right = maxSubTree(root->right);
        }
        int q = root->val;
        if(root->left){
            q  = max(root->val + left.q, q);
        }
        if(root->right){
            q = max(root->val + right.q, q);
        }

        int s = q;
        if(root->left and root->right){
            s = max(q, root->val + right.q + left.q);
        }

        int R = s;
        if(root->left){
            R = max(R, left.R);
        }
        if(root->right){
            R = max(R, right.R);
        }
        cout << R << ' ' << q << endl;
        return Record{R, q};
    }
};
#endif //SRC_MAXPATHSUMINBINARYTREE_H
