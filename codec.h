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
void printVector(vector<string> vec){
    for(auto i : vec){
        cout << i << ' ';
    }
    cout << endl;
}
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        /*
         * bfs 遍历二叉树
         * count 记录队列中非空节点的数目
         * 将根节点入队列
         * 当队列非空，且 非空节点数 大于 0， 重复
         * 队首节点为当前节点，将队首节点弹出
         * 对于当前节点， 在列表追加节点值，
         * 若节点非空，将左右子树入队列，count + 1 或 +2
         */
        queue<TreeNode *> q;
        if(root == nullptr){
            return "";
        }
        q.push(root);
        int count = 1;
        TreeNode *cur;
        vector<string> vec;
        string s;
        while(not q.empty() and count > 0){
            cur = q.front();
            q.pop();
            if(cur){
                count--;
                vec.push_back(to_string(cur->val));
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
                vec.push_back("#");
            }

        }
//        printVector(vec);
        for(auto i: vec){
            s.append(i);
            s.push_back(',');
        }
        cout << s << endl;
        return s;

    }
    TreeNode *buildTree(vector<string> vec){
        /* vec 中至少有一个数
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

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0){
            return nullptr;
        }
        vector<string> vec;
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
            vec.push_back(data.substr(i, count));
            i = i + count + 1;
        }
//        cout << "vector input for build tree: " << endl;
//        printVector(vec);
        root = buildTree(vec);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
#endif //SRC_CODEC_H
