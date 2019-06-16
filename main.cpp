#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"rob.h"
#include"numSquares.h"
using namespace std;



int main()
{
    NumberSquares solution;
//    vector<int > vec{2, 6, 3, 9, 8, 2, 1};

    int res = solution.numberSquare(0);
//    printVector(res);
    cout << "Result: " << res << endl;
}
