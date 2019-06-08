//
// Created by so_go on 2019/6/8.
//

#ifndef SRC_CODEC_H
#define SRC_CODEC_H
#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void printVector(vector<int> vec){
    for(int i : vec){
        cout << i << ' ';
    }
    cout << endl;
}
class Codec {
public:
    // TODO:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        /*
         * bfs 遍历二叉树
         * 记录当前队列中非空计数
         * 当队列非空 且 非空计数非0，将队首节点弹出，非空计数减一
         * 当队首节点为空，为左右空子树入队列
         * 当队首节点非空，则将左右字数压入队列，非空计数+1 或 + 2
         */
        queue<TreeNode *> q;
        if(root == NULL){
            return "";
        }
        q.push(root);
        TreeNode *cur;
        int count = 1;
        vector<int> vec;
        string s;
        while(not q.empty() and count != 0){
            cur = q.front();
            q.pop();
            if(cur){
                count--;
                s.push_back(cur->val);
                q.push(cur->left);
                if(cur->left){
                    count++;
                }

                q.push(cur->right);
                if(cur->right){
                    count++;
                }
            }
            else{
                s.push_back(NULL);
                q.push(NULL);
                q.push(NULL);
            }
        }
        printVector(vec);
        for(int i: vec){
            s.append(to_string(i));
            s.push_back(',');
        }
        cout << s << endl;
        return s;

    }
    TreeNode *buildTree(vector<int> vec){
        /* vec 中至少有一个数
         * i 记录 在vec中 的位置，队列 q 记录尚未添加子树的节点
         * i < size of vector:
         * 队首节点弹出队列
         * 对当前位置 i 非空, 将当前数字链接到队首节点的左子树，
         * i++
         * 如果 i < sizeof vector 且当前位置非空, 将当前数字链接到队首节点右子树，
         * i++
         * 返回根节点
         */
        queue<TreeNode *> q;
        TreeNode *root = new TreeNode(vec[0]);
        q.push(root);
        int i = 1;
        TreeNode *newNode, *curNode;
        while( i < vec.size()){
            curNode = q.front();
            q.pop();
            if(vec[i]){
                newNode = new TreeNode(vec[i]);
                curNode->left = newNode;
                q.push(newNode);

            }
            else{
                q.push(NULL);
            }
            i++;

            if( i < vec.size()){
                if(vec[i]){
                    newNode = new TreeNode(vec[i]);
                    curNode->right = newNode;
                    q.push(newNode);
                }
                else{
                    q.push(NULL);
                }
                i++;
            }
        }
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0){
            return NULL;
        }
        vector<int> vec;
        TreeNode *root;
        // i 记录当前位置， count 记录从上一位置非','的记录数
        // 遍历数组，当当前字符非',', count++
        // 当前字母为','，截取子串substr(i, count)
        // 位置记录更新为 i + count + 1;
        int i = 0, count = 0;
        while( i != data.size()){
            count = 0;
            while(data[i + count] != ','){
                count++;
            }
            vec.push_back(stoi(data.substr(i, count)));
            i = i + count + 1;
        }
        for(int i : vec){
            cout << i << ' ';
        }
        cout << endl;
        root = buildTree(vec);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
#endif //SRC_CODEC_H
