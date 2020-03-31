//
// Created by so_go on 2020/3/30.
//
/*
 * 23. 合并K个排序链表

合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6


 */
#ifndef SRC_MERGEKORDEREDLIST_H
#define SRC_MERGEKORDEREDLIST_H
#include<bits/stdc++.h>
using namespace std;

 //* Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 struct compare{
     bool operator ()(ListNode *a, ListNode *b){
         if(a->val > b->val){
             return true;
         }
         return false;
     }
 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode*>, compare> hp;
        for(ListNode *node : lists){
            if(node != NULL){
                hp.push(node);
            }
        }
        ListNode *start = NULL;
        if(not hp.empty()){
            start = hp.top();
            hp.pop();
            if(start->next != NULL){
                hp.push(start->next);
            }
        }
        ListNode *cur = start;
        while(not hp.empty()){
            ListNode *tp = hp.top();
            cur->next = tp;
            hp.pop();
            if(tp->next != NULL){
                hp.push(tp->next);
            }
            cur = tp;
        }
        return start;
    }
};
#endif //SRC_MERGEKORDEREDLIST_H
