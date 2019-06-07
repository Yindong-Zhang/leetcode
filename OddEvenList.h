//
// Created by so_go on 2019/6/7.
//

#ifndef SRC_ODDEVENLIST_H
#define SRC_ODDEVENLIST_H
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

class OddEvenList {
public:
    ListNode* oddEvenList(ListNode* head) {
        // 从 0 开始编号
        // 当遇到编号为偶数的节点，即在偶数链表进行尾插，并在原位置删除节点。
        if(head == NULL){
            return NULL;
        }
        ListNode *cur = head->next, *last = head, *evenlast = head;
        int num = 1;
        while(cur){
            cout << last->val << "->" << cur->val << endl;
            if(num % 2 == 0){
                last->next = cur->next;

                //
                cur->next = evenlast->next;
                evenlast->next = cur;
                evenlast = cur;

                // last 不变， cur 前进一步
                cur = last->next;
            }
            else{
                last = cur;
                cur = cur->next;
            }

            num++;
        }
        return head;
    }
};
#endif //SRC_ODDEVENLIST_H
