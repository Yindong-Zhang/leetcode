#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"printVector.h"
#include"combinationSumI_39.h"
using namespace std;



int main()
{
    CombinationSum39 solution;
//    vector<int> days = {1,4,6,7,8,20}, costs = {2,7,15};
    vector<int> nums = {2, 3, 6, 7};
    int target = 7;
//    int target = -100;
//    string s= "abcde", p = "abcde";
//    string s= "+e";
    auto res = solution.combinationSum(nums, target);
//    cout << res << endl;
    for(auto vec : res){
        printVector(vec);
    }
//    printVector(res);
//    cout << "Result: " << res << endl;
}
