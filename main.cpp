#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"sortList.h"
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
    SortList solution;
    vector<int> vec{4,2, 5, 3, 7, 9, 0, 1};
    ListNode *head = buildList(vec);
    printList(head);
    head =  solution.sortList(head) ;
    printList(head);

}
