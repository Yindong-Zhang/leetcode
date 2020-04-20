//
// Created by so_go on 2020/4/20.
//
/*
 * 109. 有序链表转换二叉搜索树

给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定的有序链表： [-10, -3, 0, 5, 9],

一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5


 */
#ifndef SRC_LIST2BST_H
#define SRC_LIST2BST_H
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return ConquerAndDivide(head, NULL);
    }

    TreeNode *ConquerAndDivide(ListNode *begin, ListNode *end){
        if(begin == end){
            return NULL;
        }
        ListNode *fastPtr = begin, *slowPtr = begin;
        while(fastPtr->next != end and fastPtr->next->next != end){ // 快慢指针
            fastPtr = fastPtr->next->next;
            slowPtr = slowPtr->next;
        }
        if(fastPtr->next != end){
            slowPtr = slowPtr->next; //// 偶数情况下，依照题意，左子树多，右子树少
        }
        // cout << slowPtr->val << endl;
        TreeNode *root = new TreeNode(slowPtr->val);
        root->left = ConquerAndDivide(begin, slowPtr);
        root->right = ConquerAndDivide(slowPtr->next, end);
        return root;
    }
};
};
#endif //SRC_LIST2BST_H
