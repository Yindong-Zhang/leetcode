//
// Created by so_go on 2020/4/11.
//
/*
 * 86. 分隔链表

给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

示例:

输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5


 */
#ifndef SRC_SPLITLIST_86_H
#define SRC_SPLITLIST_86_H
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
    ListNode* partition(ListNode* head, int x) {
        ListNode ls(0), rs(0); // 头节点是个好东西
        ListNode *le = &ls, *re = &rs;
        ListNode *cur = head;
        while(cur != NULL){
            if(cur->val < x){
                le->next = cur;
                le = cur;

            }
            else{
                re->next = cur;
                re = cur;
            }
            cur = cur->next;
        }
        re->next = NULL;
        le->next = rs.next;
        return ls.next;

    }
};
#endif //SRC_SPLITLIST_86_H
