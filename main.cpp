#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"printVector.h"
#include"reachPoints_780.h"
using namespace std;



int main()
{
    ReachPoints solution;
//    vector<int> days = {1,4,6,7,8,20}, costs = {2,7,15};
//    vector<int> nums = {3, 2, 3};
//    vector<vector<int>> a{{-2, -3, 3},
//                          {-5, -10, 1},
//                          {10, 30, -5}};
//    int target = -100;
//    string s= "abcde", p = "abcde";
//    string s= "+e";
    int sx = 1, sy = 1, tx = 3, ty = 5;
    auto res = solution.reachingPoints(sx, sy, tx, ty);
//    cout << res << endl;
//    for(auto vec : res){
//        printVector(vec);
//    }
//    printVector(res);
    cout << "Result: " << res << endl;
}
