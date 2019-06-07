//
// Created by yindong on 19-6-6.
//

#ifndef SRC_SORTLIST_H
#define SRC_SORTLIST_H
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

// TODO:
class SortList {
public:
    ListNode* sortList(ListNode* head) {
        quickSort(head, NULL);
        return head;
    }

    ListNode *partition(ListNode *start, ListNode *end){
        // 左闭右开　[start, end)
        ListNode *p = start, *q = start;
        int pivot = start->val;
        while(true){
            // q 找到下一个小于pivot 的位置
            while( q != end and q->val >= pivot ){
                q = q->next;
            }
            if( q != end){
                p->val = q->val;
                printList(start);
            }
            else{
                break;
            }

            // p 找到下一个大于　pivot　的位置，　与　q 交换。

            while( p->val <= pivot and p != q){
                p = p->next;
            }
            if( p != q){
                q->val = p->val;
                printList(start);
            }
            else{
                q = q->next;
            }
        }
        p->val = pivot;
        return p;
    }

    void quickSort(ListNode *start, ListNode *end){
        // 左开右闭　[start, end)
        //  停止条件
        if( start == end or start->next == end){
            return;
        }
        //递归
        ListNode *pivot = partition(start, end);
        printList(start);
        quickSort(start, pivot);
        quickSort(pivot->next, end);

    }

};
#endif //SRC_SORTLIST_H
