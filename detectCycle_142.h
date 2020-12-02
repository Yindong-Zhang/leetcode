//
// Created by so_go on 2020/7/19.
//
/*
 * 142. 环形链表 II

给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

说明：不允许修改给定的链表。



示例 1：

输入：head = [3,2,0,-4], pos = 1
输出：tail connects to node index 1
解释：链表中有一个环，其尾部连接到第二个节点。

 */
#ifndef SRC_DETECTCYCLE_142_H
#define SRC_DETECTCYCLE_142_H
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 改进的双指针法，找到重合位置后，定义一个新指针指向头节点，与重合指针同步后移，新指针与重合指针重合位置就是环入口。
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *p1 = head, *p2= head;
        bool isCycle= false;
        while(p2 != NULL and p2->next != NULL){
            p2 = p2->next->next;
            p1 = p1->next;
            if(p1 == p2){
                isCycle= true;
            }
        }
        if(not isCycle){
            return NULL;
        }
        ListNode *p3= head;
        while(p1 != p3){
            p1 = p1->next;
            p3 = p3->next;
        }
        return p1;
    }
};
#endif //SRC_DETECTCYCLE_142_H
