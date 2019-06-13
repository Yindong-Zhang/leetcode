#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"findPeak.h"
#include"printVector.h"
using namespace std;



int main()
{
    FindPeak solution;
    vector<int> vec{1,0,1,3,5,6,4};
    int res = solution.findPeakElement(vec);
    cout << "Result: " << res << endl;
}
