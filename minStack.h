//
// Created by so_go on 2019/5/29.
//

#ifndef SRC_MINSTACK_H
#define SRC_MINSTACK_H
#include<vector>
#include<stack>
using namespace std;
class MinStack {
private:
    /* data 记录栈中的数据，
    //  asc_ptr: ascending pointer 记录比当前位置大的下一个数据的 位置， 即 升序指针
    事实上，当栈当前压入的数大于栈最小的值，不管压入和弹出栈时最小值都无需任何更改。
     min_stk 存储依次遇到的最小值在栈中的位置
    */
    stack<int> data;
    stack<int> min;
public:
    /** initialize your data structure here. */
    void push(int x) {
        data.push(x);
        cout << "Is empty: " << min.empty() << endl;
        if( min.empty() || x <= min.top()){
            min.push(x);
        }
    }

    void pop() {
        if(data.top() == min.top()){
            min.pop();
        }
        data.pop();
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return min.top();
    }
};
#endif //SRC_MINSTACK_H
