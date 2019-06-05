//
// Created by yindong on 19-6-5.
//

#ifndef SRC_HASCYCLELIST_H
#define SRC_HASCYCLELIST_H
#include<iostream>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class HasCycle {
public:
    bool hasCycle(ListNode *head) {
        // 设置两个指针，一个指针慢，　两步进一个，　一个指针快，一步进一个，如果出现环，快的指针一定会追上慢的指针,
        // 当快指针等于慢指针，　则有环
        // 对于快的指针，当指针为空，则无环
        ListNode *slow_ptr = head, *fast_ptr = head;
        if(head == NULL){
            return false;
        }
        int i = 1;
        do{
            fast_ptr = fast_ptr->next;
            if(i % 2 == 0){
                slow_ptr = slow_ptr->next;
            }
            i++;
        }while(fast_ptr and fast_ptr != slow_ptr);
        if(fast_ptr == NULL){
            return false;
        }
        else{
            return true;
        }
    }
};
#endif //SRC_HASCYCLELIST_H
