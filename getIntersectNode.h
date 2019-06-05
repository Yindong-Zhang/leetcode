//
// Created by so_go on 2019/6/5.
//

#ifndef SRC_GETINTERSECTNODE_H
#define SRC_GETINTERSECTNODE_H
#include<iostream>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class GetIntersectionNode {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptrA = headA, *ptrB = headB;
        int sizeA = 0, sizeB = 0;
        while(ptrA){
            sizeA++;
            ptrA = ptrA->next;
        }

        while(ptrB){
            sizeB++;
            ptrB = ptrB->next;
        }
        cout << sizeA << ' ' << sizeB << endl;
        ptrA = headA;
        ptrB = headB;
        if(sizeA > sizeB){
            for(int i = 0; i < sizeA - sizeB; i++){
                ptrA = ptrA->next;
            }
        }
        else{
            for(int i =0; i< sizeB - sizeA; i++){
                ptrB = ptrB->next;
            }
        }
        while(ptrA != ptrB){
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }
        return ptrA;
    }

};
#endif //SRC_GETINTERSECTNODE_H
