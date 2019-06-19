#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"printVector.h"
#include"fraction2Decimal.h"
using namespace std;



int main()
{
    Fraction2Decimal solution;
    auto res = solution.fractionToDecimal(-2147483648, 1);
//    printVector(res);
    cout << "Result: " << res << endl;
}
