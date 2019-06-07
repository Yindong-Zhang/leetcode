//
// Created by so_go on 2019/6/6.
//

#ifndef SRC_DELETENODE_H
#define SRC_DELETENODE_H
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
    void deleteNode(ListNode* node) {
        // 找不到前驱节点，将当前节点的后裔节点的值复制过来，改为删除下一节点。
        ListNode *next = node->next;
        node->val = next->val;
        node->next = next->next;
    }
};
#endif //SRC_DELETENODE_H
