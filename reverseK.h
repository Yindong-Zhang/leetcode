//
// Created by so_go on 2020/4/23.
//

#ifndef SRC_REVERSEK_H
#define SRC_REVERSEK_H
# include <bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};

list_node * input_list()
{
    int val, n;
    scanf("%d", &n);
    list_node * phead = new list_node();
    list_node * cur_pnode = phead;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &val);
        if (i == 1) {
            cur_pnode->val = val;
            cur_pnode->next = NULL;
        }
        else {
            list_node * new_pnode = new list_node();
            new_pnode->val = val;
            new_pnode->next = NULL;
            cur_pnode->next = new_pnode;
            cur_pnode = new_pnode;
        }
    }
    return phead;
}


list_node * reverse_knode(list_node * head1, int K)
{
    //////在下面完成代码
    int count = 0;
    list_node *ptr = head1;
    while(ptr != NULL){
        count++;
        ptr = ptr->next;
    }
    return recursive_reverse(head1, count, K);
}

list_node *recursive_reverse(list_node *head, int resCount, int K){
    if(resCount < K){
        return head;
    }
    list_node *curPtr = head->next, *lastPtr = head, *nextPtr;
    int count = 1;
    while(count < K){
        nextPtr = curPtr->next;
        curPtr->next = lastPtr;
        curPtr = nextPtr;
        lastPtr = curPtr;
        count++;
    }
    head->next = recursive_reverse(nextPtr, resCount - K, K);
    return lastPtr;
}

void print_list(list_node * head)
{
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    puts("");
}

int main ()
{
    list_node * head = input_list();
    int K;
    scanf("%d", &K);
    list_node * new_head = reverse_knode(head, K);
    print_list(new_head);
    return 0;
}
#endif //SRC_REVERSEK_H
