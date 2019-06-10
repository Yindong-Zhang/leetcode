#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"largestNumber.h"
using namespace std;



int main()
{
    LargestNumber solution;
    vector<int> vec{0, 0, 0, 0};
    string res= solution.largestNumber(vec);
    cout << "result: " << res << endl;
}
