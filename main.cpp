#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"printVector.h"
#include"getSumWithoutAdd.h"
using namespace std;



int main()
{
    GetSumWithoutAdd solution;
//    vector<vector<int>> box{ {0, 1, 3}};
//    auto t = solution.transform(52);
//    cout << t << endl;
    auto res = solution.getSum(22, -1);
    cout << "Result: " << res << endl;
}
