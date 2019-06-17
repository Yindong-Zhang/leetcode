#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"numIslands.h"
using namespace std;



int main()
{
    NumIslands solution;
    vector<vector<char >> m{{'0', '0', '0', '0', '0'},
                          {'0', '0', '0', '0', '0'},
                          {'0', '0', '0', '0', '0'},
                          {'0', '0', '0', '0', '0'}};

    int res = solution.numIslands(m);
//    printVector(res);
    cout << "Result: " << res << endl;
}
