//
// Created by so_go on 2020/1/12.
//
/*
 * 序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。

请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

示例:

你可以将以下二叉树：

    1
   / \
  2   3
     / \
    4   5

序列化为 "[1,2,3,null,null,4,5]"

提示: 这与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

说明: 不要使用类的成员 / 全局 / 静态变量来存储状态，你的序列化和反序列化算法应该是无状态的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#ifndef SRC_PREORDERSERIALIZEDESERIALIZEBINARYTREE_H
#define SRC_PREORDERSERIALIZEDESERIALIZEBINARYTREE_H
#include<iostream>
#include<sstream>
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        preOrderSerialize(root, res);
        return res;
    }

    void preOrderSerialize(TreeNode *root, string &s){
        if(root == nullptr){
            s.push_back('#');
            s.push_back(',');
            return;
        }

        s.append(to_string(root->val));
        s.push_back(',');
        preOrderSerialize(root->left, s);
        preOrderSerialize(root->right, s);

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return preOrderDeserialzie(ss);
    }

    TreeNode *preOrderDeserialzie(stringstream &ss){
        if(ss.peek() != '#'){
            int val;
            ss >> val;
            ss.get();
            TreeNode *node = new TreeNode(val);
            node->left = preOrderDeserialzie(ss);
            node->right = preOrderDeserialzie(ss);
            return node;
        }
        else{
            ss.get(); // #
            ss.get(); // ,
            return nullptr;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
#endif //SRC_PREORDERSERIALIZEDESERIALIZEBINARYTREE_H
