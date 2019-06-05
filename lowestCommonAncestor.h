//
// Created by so_go on 2019/6/5.
//

#ifndef SRC_LOWESTCOMMONANCESTOR_H
#define SRC_LOWESTCOMMONANCESTOR_H
//Definition for a binary tree node.
#include<stack>
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Record{
    TreeNode *node;
    int count;
};

class LowestCommonAncestor {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /* 当栈非空
 * 当前栈顶节点，
 * 若节点非空，
 * 当标记为0，左子树入栈，当前标记++，左子树标记为0
 * 当标记为1， 右子树入栈，当前标记++， 右子树标记为0，
 * 若标记为2，退栈
 * 若节点为空，退栈
 */
        stack<Record> s, s_p, s_q;
        bool p_find = false, q_find = false;
        TreeNode *cur = root;
        s.push({cur, 0});
        while(not s.empty() and (not p_find or not q_find)){
            if(s.top().node == p) {
                s_p = s;
                p_find = true;
            }

            if(s.top().node == q) {
                s_q = s;
                q_find = true;
            }
            if(s.top().node != NULL) {
                // cout << s.top().node->val << endl;
                if (s.top().count == 0) {
                    s.top().count++;
                    s.push({s.top().node->left, 0});
                } else if (s.top().count == 1) {
                    s.top().count++;
                    s.push({s.top().node->right, 0});
                } else if (s.top().count == 2) {
                    s.pop();
                } else {
                    cout << "ERROR OCCUR." << endl;
                }
            }
            else{
                s.pop();

            }
        }
        cout << "stack q size: " << s_q.size() << endl;
        cout << "stack p size: " << s_p.size() << endl;
        int sq_size = s_q.size(), sp_size = s_p.size();
        if(sp_size < sq_size){
            for(int i = 0; i < sq_size - sp_size; i++){
                cout << i << endl;
                s_q.pop();
            }
        }
        else{
            for(int i = 0; i < sp_size - sq_size; i++){
                cout << i << endl;
                s_p.pop();
            }
        }
        cout << s_q.size() << ' ' << s_p.size() << endl;
        while(s_q.top().node != s_p.top().node){
            s_q.pop();
            s_p.pop();
        }

        return s_q.top().node;
    }
};
#endif //SRC_LOWESTCOMMONANCESTOR_H
