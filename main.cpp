#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"singleNumber.h"
using namespace std;



int main()
{
    SingleNumber solution;
    vector<int> nums{2, 2 ,1};
    auto res = solution.singleNumber(nums );
//    printVector(res);
    cout << "Result: " << res << endl;
}
