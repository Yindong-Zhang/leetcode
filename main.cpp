#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"OddEvenList.h"
using namespace std;

ListNode *buildList(vector<int> a){
    ListNode *cur, *last, *head;
    head = new ListNode(a[0]);
    last = head;
    for(int i = 1; i < a.size(); i++){
        cur = new ListNode(a[i]);
        last->next = cur;
        last = cur;
    }
    return head;
}

int main()
{
    OddEvenList solution;
    vector<int> vec{1, 2, 3, 4, 5};
    ListNode *head = buildList(vec);
    printList(head);
    ListNode *res =  solution.oddEvenList(head);
    printList(res);
}
