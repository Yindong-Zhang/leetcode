#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"evalReversePorlandExpression.h"
using namespace std;
int main()
{
    EvalRPN solution;
    vector<string> vec_str{"4", "13", "5", "/", "+"};
    int res=  solution.evalRPN(vec_str) ;
    cout << res << endl;

}
