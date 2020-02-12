#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"printVector.h"
#include"minWindow_76.h"
using namespace std;



int main()
{
    MinWindow solution;
//    vector<int> test{7,2,5,10,8};
    string s = "aa", p = "aa";
//    cout << solution.F(15, test, 2) << endl;
    auto res = solution.minWindow(s, p);
    cout << res << endl;
//    for(auto vec : res){
//        printVector(vec);
//    }
//    printVector(test);
//    cout << "Result: " << res << endl;
}
