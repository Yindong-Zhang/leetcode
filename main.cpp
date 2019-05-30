#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"kthSmallestInOrderedMatrix.h"
using namespace std;

int main()
{
    KthSmallestInOrderMatrix solution;
    vector<vector<int>> vec{{1, 5, 9},
                            {10, 11, 14},
                            {12, 13, 15}};
    cout << solution.kthSmallest(vec, 8) << endl;

}
