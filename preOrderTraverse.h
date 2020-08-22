#include<bits/stdc++.h>
using namespace std;



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> preorderTraversal_1(TreeNode* root) {
            stack<TreeNode *> st;
            TreeNode *curNode = root;
            vector<int> res;
            while(not st.empty()){
                while(curNode != NULL){
                    st.push(curNode);
                    res.push_back(curNode->val);
                    curNode = curNode->left;
                }
                curNode = st.top();
                st.pop();
                curNode = curNode->right;

            }
            return res;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode *> st;
        TreeNode *curNode = root;
        vector<int> res;
        while(curNode != NULL or not st.empty()){
            if(curNode != NULL){
                st.push(curNode);
                res.push_back(curNode->val);
                curNode = curNode->left;
            }
            else{
                curNode = st.top();
                st.pop();
                curNode = curNode->right;
            }
        }
        return res;
    }
};