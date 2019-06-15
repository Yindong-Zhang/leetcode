#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"longestConsecutive.h"
#include"printVector.h"
using namespace std;



int main()
{
    LongestConsecutive solution;
    vector<int > vec{};
    int res = solution.longestConsecutive(vec);
//    printVector(res);
    cout << "Result: " << res << endl;
}
