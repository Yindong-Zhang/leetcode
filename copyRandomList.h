//
// Created by yindong on 19-6-3.
//

#ifndef SRC_COPYRANDOMLIST_H
#define SRC_COPYRANDOMLIST_H



// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

#include<map>
using namespace std;

class Solution {
public:
    map<Node*, Node*> m;
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }
        Node *cur, *new_cur, *new_last, *new_head;
        new_head = new Node(head->val, NULL, NULL);
        // new_head->val = head->val;
        // cout << "insert: " << head << ' ' << new_head << endl;
        m.insert({head, new_head});
        cur = head->next;
        new_last = new_head;
        // 遍历链表，进行深拷贝
        while(cur != NULL){
            new_cur = new Node(cur->val, NULL, NULL);
            // new_cur->val = cur->val;
            new_last->next = new_cur;
            // cout << "insert: " << cur << ' ' << new_cur << endl;
            m.insert({cur, new_cur});
            cur = cur->next;
            new_last = new_cur;


        }

        // 再次遍历新旧链表，找到每个随机指针对应的新节点，将新链表的随机指针指向新节点

        Node *ptr = head, *new_ptr = new_head;
        while(ptr != NULL){
            if(ptr->random != NULL){
                cout << ptr->random << ' ' << m[ptr->random] << endl;
                new_ptr->random = m[ptr->random];
            }
            else{
                new_ptr->random = NULL;
            }

            ptr= ptr->next;
            new_ptr = new_ptr->next;
        }

        return new_head;
    }
};
#endif //SRC_COPYRANDOMLIST_H
