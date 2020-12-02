

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<pair<TreeNode *, int>> st;
        TreeNode *curNode = root;
        vector<int> res;
        while(curNode != NULL or not st.empty()){
            if(curNode == NULL){
                auto p = st.top(); // top() 函数返回一个引用
                if(p.second == 1){
                    curNode = p.first->right;
                    p.second++;
                }
                else{
                    res.push_back(p.first->val);
                    st.pop();
                }
            }
            else{
                st.push({curNode, 1});
                curNode = curNode->left;
            }
        }
        return res;
    }
};