//
// Created by yindong on 19-6-2.
//

#ifndef SRC_CALCULATOR_H
#define SRC_CALCULATOR_H
#include<string>
#include<stack>
#include<array>
#include<iostream>
#include<cctype>
using namespace std;

class Calculator {
public:
    int op2card(char ch){
        int card = -1;
        if(ch == '+')
            card = 0;
        else if(ch == '-')
            card = 1;
        else if(ch == '*')
            card = 2;
        else if(ch == '/')
            card = 3;
        else
            cout << "Error!!!" << endl;
        return card;
    }

    // + - * /
    // a[i][j] = 1 if priority of op[i] >= op[j]
    int evaluate(char op, int a, int b){
        int res = 0;
        switch(op){
            case '+':{
                res = a + b;
                break;
            }
            case '-':{
                res = a - b;
                break;
            }
            case '*':{
                res = a * b;
                break;
            }
            case '/':{
                res = a / b;
                break;
            }
            default:{
                cout << "Error!!!" << endl;
            }
        }
        return res;
    }

    array<array<bool , 4>, 4> priority = {{
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1}
    }};

    int calculate(string s) {
        stack<char> op_stack;
        stack<int> num_stack;
        int a, b, res;
        char op;
        string num_str;
        auto ptr = s.begin();
        while(ptr != s.end()){
            if( *ptr == ' '){
                ptr++;
            }
            else if( *ptr == '+' || *ptr == '-' || *ptr == '*' || *ptr == '/'){
                if(op_stack.empty() or not priority[op2card(op_stack.top())][op2card(*ptr)]){
                    op_stack.push(*ptr);
//                    cout << "operator stack push: " << *ptr << endl;
                    ptr++;
                }
                else if(priority[op2card(op_stack.top())][op2card(*ptr)]){
                    b = num_stack.top(); num_stack.pop();
                    a = num_stack.top(); num_stack.pop();
//                    cout << "num stack pop: " << a << b << endl;
                    op = op_stack.top(); op_stack.pop();
//                    cout << "op stack pop: " << op << endl;
                    res = evaluate(op, a, b);
                    num_stack.push(res);
//                    cout << "num stack push: " << res << endl;

                }
            }
            else if(isdigit(*ptr)){
                while(ptr != s.end() and isdigit(*ptr)){
                    num_str.push_back(*ptr);
                    ptr++;
                }
                num_stack.push(stoi(num_str));
                num_str.clear();
//                cout << "num stack push: " << num_str << endl;
            }
            else{
                cout << "Error!!!" << endl;
            }
        }
        while(not op_stack.empty()){
            op = op_stack.top(); op_stack.pop();
            b = num_stack.top(); num_stack.pop();
            a = num_stack.top(); num_stack.pop();
            num_stack.push(evaluate(op, a, b));
        }

//        cout << "Size of number stack: " << num_stack.size() << endl;
//        cout << "Size of operator stack: " << op_stack.size() << endl;
        return num_stack.top();
    }
};
#endif //SRC_CALCULATOR_H
