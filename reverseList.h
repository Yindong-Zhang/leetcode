//
// Created by so_go on 2019/6/6.
//

#ifndef SRC_REVERSELIST_H
#define SRC_REVERSELIST_H
#include<iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        ListNode *ptr, *rptr, *new_node;
        rptr = new ListNode(head->val);
        ptr = head->next;
        while(ptr){
            new_node = new ListNode(ptr->val);
            new_node->next = rptr;
            rptr = new_node;
            ptr = ptr->next;
        }
        return rptr;
    }
};
#endif //SRC_REVERSELIST_H
