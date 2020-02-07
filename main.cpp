#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"printVector.h"
#include"isMatch.h"
using namespace std;



int main()
{
    IsMatch solution;
    vector<int> test{1,2,3};
    string s = "aab", p = "c*a*b";
    cout << solution.isMatch(s, p);
//    for(auto vec : res){
//        printVector(vec);
//    }
//    printVector(test);
//    cout << "Result: " << res << endl;
}
