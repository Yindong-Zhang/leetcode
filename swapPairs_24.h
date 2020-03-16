//
// Created by so_go on 2020/3/16.
//
/*
 * 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。



示例:

给定 1->2->3->4, 你应该返回 2->1->4->3.

通过次数81,218
提交次数125,480

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/swap-nodes-in-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#ifndef SRC_SWAPPAIRS_24_H
#define SRC_SWAPPAIRS_24_H
#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {};
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        return swapPairsRecursive(head);

    }

    ListNode* swapPairsRecursive(ListNode *curNode){
        if(curNode != nullptr and curNode->next != nullptr){
            ListNode *a = curNode, *b = curNode->next;
            ListNode *n = b->next;
            b->next = a;
            a->next = swapPairsRecursive(n);
            return b;
        }
        return curNode;
    }
};
#endif //SRC_SWAPPAIRS_24_H
