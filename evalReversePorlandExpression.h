//
// Created by yindong on 19-6-3.
//

#ifndef SRC_EVALREVERSEPORLANDEXPRESSION_H
#define SRC_EVALREVERSEPORLANDEXPRESSION_H
#include<vector>
#include<string>
#include<iostream>
#include<stack>
using namespace std;

class EvalRPN {
public:
    stack<int> s;
    int evaluate(string op, int a, int b) {
        int res = 0;
        if(op == "+"){
            res = a + b;
        }
        else if(op ==  "-"){
            res = a - b;
        }
        else if(op ==  "*"){
            res = a * b;
        }
        else if(op == "/") {
            res = a / b;
        }
        else{
            cout << "Error!!!" << endl;
        }
        return res;
    }

    bool isOperator(string s){
        if(s == "+" or s == "-" or s == "*" or s == "/")
            return true;
        else
            return false;
    }

    int evalRPN(vector<string>& tokens) {
        int a, b, res;
        for(auto ptr = tokens.begin(); ptr != tokens.end(); ptr++){
            if(isOperator(*ptr)){
                b = s.top(); s.pop();
                a = s.top(); s.pop();
                res = evaluate(*ptr, a, b);
                s.push(res);
            }
            else{
                s.push(stoi(*ptr));
            }

        }
        cout << "size of stack: " << s.size() << endl;
        return s.top();

    }
};
#endif //SRC_EVALREVERSEPORLANDEXPRESSION_H
