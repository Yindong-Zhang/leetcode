#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"printVector.h"
#include"isMatch_44.h"
using namespace std;



int main()
{
    IsMatch44 solution;
//    vector<int> days = {1,4,6,7,8,20}, costs = {2,7,15};
//    vector<int> nums = {1, 1, 1, 0};
//    int target = -100;
    string s= "abcde", p = "abcde";
    auto res = solution.isMatch(s, p);
    cout << res << endl;
//    for(auto vec : res){
//        printVector(vec);
//    }
//    printVector(res);
//    cout << "Result: " << res << endl;
}
