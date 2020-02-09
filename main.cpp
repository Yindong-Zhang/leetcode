#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"printVector.h"
#include"findDisappearedNumbers.h"
using namespace std;



int main()
{
    FindDisappearedNumbers solution;
    vector<int> test{4,3,2,7,8,2,3,1};
//    string s = "aab", p = "c*a*b";
    auto res = solution.findDisappearedNumbers(test);
    printVector(res);
//    for(auto vec : res){
//        printVector(vec);
//    }
//    printVector(test);
//    cout << "Result: " << res << endl;
}
