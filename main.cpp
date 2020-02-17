#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"printVector.h"
#include"editDistance_72.h"
using namespace std;



int main()
{
    MinDistance solution;
//    vector<int> test{2,1,5,6,2,3};
    string s = "intention", p = "execution";
//    cout << solution.F(15, test, 2) << endl;
    auto res = solution.minDistance(s, p);
    cout << res << endl;
//    for(auto vec : res){
//        printVector(vec);
//    }
//    printVector(test);
//    cout << "Result: " << res << endl;
}
