#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"printVector.h"
#include"combinationSumII.h"
using namespace std;



int main()
{
    CombinationSumII solution;
    vector<int> test{10,1,2,7,6,1,5};
    auto res = solution.combinationSum2(test, 8);
    for(auto vec : res){
        printVector(vec);
    }
//    cout << "Result: " << res << endl;
}
