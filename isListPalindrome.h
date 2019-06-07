//
// Created by so_go on 2019/6/6.
//

#ifndef SRC_ISLISTPALINDROME_H
#define SRC_ISLISTPALINDROME_H
#include<iostream>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode *head){
    ListNode *cur = head;
    while(cur){
        cout << cur->val << ' ';
        cur = cur->next;
    }
    cout << endl;
}

class IsListPalindrome {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *cur = head;
        int count = 0;
        while(cur){
            cur = cur->next;
            count++;
        }
        cout << count << endl;
        int half = count / 2;
        // 将前半部分原地逆置。
        // 对于当前节点，保存下一个节点，将当前节点插入链表头部
        ListNode *rhead = NULL, *next;
        cur = head;
        for(int i = 0; i < half; i++){
            next = cur->next;
            cur->next = rhead;
            rhead = cur;
            cur = next;
        }
        printList(rhead);
        printList(cur);

        ListNode *rptr = rhead;
        if( count % 2 == 0){
            for(int i = 0; i < half; i++){
                if( rptr->val != cur->val){
                    return false;
                }
                rptr = rptr->next;
                cur = cur->next;
            }
        }
        else{
            cur = cur->next;
            for(int i = 0; i < half; i++){
                if(rptr->val != cur->val){
                    return false;
                }
                rptr = rptr->next;
                cur = cur->next;
            }
        }
        return true;
    }
};
#endif //SRC_ISLISTPALINDROME_H
