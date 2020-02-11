#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"printVector.h"
#include"sumSubarrayMins.h"
using namespace std;



int main()
{
    SumSubArrayMins solution;
    vector<int> test{71,55,82,55};
//    string s = "aab", p = "c*a*b";
    auto res = solution.sumSubarrayMins(test);
    cout << res << endl;
//    for(auto vec : res){
//        printVector(vec);
//    }
//    printVector(test);
//    cout << "Result: " << res << endl;
}
