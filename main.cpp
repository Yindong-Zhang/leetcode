#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"longestIncreasingPathInMatrix.h"
using namespace std;



int main()
{
    LongestIncreasingPathinMatrix solution;
    vector<vector<int>> m{};

    int res = solution.longestIncreasingPath(m);
//    printVector(res);
    cout << "Result: " << res << endl;
}
