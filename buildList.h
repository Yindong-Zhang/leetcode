//
// Created by yindong on 19-6-6.
//

#ifndef SRC_BUILDLIST_H
#define SRC_BUILDLIST_H
#include<vector>
#include"sortList.h"
using namespace std;

ListNode *buildList(vector<int> a){
    ListNode *cur, *last, *head;
    head = new ListNode(a[0]);
    last = head;
    for(int i = 1; i < a.size(); i++){
        cur = new ListNode(a[i]);
        last->next = cur;
    }
    return head;
}
#endif //SRC_BUILDLIST_H
