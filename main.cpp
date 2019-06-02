#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"calculator.h"
using namespace std;
int main()
{
    Calculator solution;
    string s("3 + 5 / 2 - 3 * 2");
    int res=  solution.calculate(s) ;
    cout << res << endl;

}
