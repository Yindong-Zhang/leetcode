#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"printVector.h"
#include"threeSumClosest.h"
using namespace std;



int main()
{
    ThreeSumClosest solution;
//    vector<int> days = {1,4,6,7,8,20}, costs = {2,7,15};
    vector<int> nums = {1, 1, 1, 0};
    int target = -100;
    auto res = solution.threeSumClosest(nums, 1);
    cout << res << endl;
//    for(auto vec : res){
//        printVector(vec);
//    }
//    printVector(res);
//    cout << "Result: " << res << endl;
}
