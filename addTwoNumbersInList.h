//
// Created by so_go on 2020/4/6.
//
/*
 * 给定两个非空链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储单个数字。将这两数相加会返回一个新的链表。



你可以假设除了数字 0 之外，这两个数字都不会以零开头。

进阶:

如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。

示例:

输入: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
输出: 7 -> 8 -> 0 -> 7

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#ifndef SRC_ADDTWONUMBERSINLIST_H
#define SRC_ADDTWONUMBERSINLIST_H
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /*
     * 递归法
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l1_node = l1, *l2_node = l2;
        int i = 0, j = 0;
        while(l1_node != NULL){
            l1_node = l1_node->next;
            i++;
        }
        while(l2_node != NULL){
            l2_node = l2_node->next;
            j++;
        }
        int jw;
        ListNode *lastNode;
        if(i >= j){
            lastNode = recursive_add(l1, l2, i, j, jw);
        }
        else{
            lastNode = recursive_add(l2, l1, j, i, jw);
        }

        if(jw == 0){
            return lastNode;
        }
        else{
            ListNode *node = new ListNode(1);
            node->next = lastNode;
            return node;
        }
    }
     */

    // 应用双栈
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> a, b;
        while(l1 != NULL){
            a.push(l1->val);
            l1 = l1->next;
        }
        while(l2 != NULL){
            b.push(l2->val);
            l2 = l2->next;
        }
        return stackSolve(a, b);
    }
    ListNode *stackSolve(stack<int> &a, stack<int> &b){
        int jw = 0;
        ListNode *lastNode = NULL, *curNode= NULL;
        while(not a.empty() or not b.empty()){
            int na = 0, nb = 0, curSum;
            if(not a.empty()){
                na = a.top();
                a.pop();
            }
            if(not b.empty()){
                nb = b.top();
                b.pop();
            }
            curSum = na + nb + jw;
            jw = curSum / 10;
            curNode = new ListNode(curSum % 10);
            curNode->next = lastNode;
            lastNode = curNode;
        }
        if(jw != 0){
            curNode = new ListNode(jw);
            curNode->next = lastNode;
        }
        return curNode;
    }
    // 递归解法
    ListNode* recursive_add(ListNode *l1, ListNode* l2, int i, int j, int &jw){
        // cout << i << ' ' << j << endl;
        if(l1 == NULL and l2 == NULL){
            jw = 0;
            return NULL;
        }
        int ljw, curSum;
        ListNode* curNode= new ListNode(0);
        if(i == j){
            curNode->next = recursive_add(l1->next, l2->next, i - 1, j - 1, ljw);
            curSum = l1->val + l2->val + ljw;

        }
        else{
            curNode->next = recursive_add(l1->next, l2, i - 1, j, ljw);
            curSum = l1->val + ljw;

        }
        curNode->val = curSum % 10;
        jw = curSum / 10;
        return curNode;
    }
};
#endif //SRC_ADDTWONUMBERSINLIST_H
