#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"topologicalSort.h"
using namespace std;



int main()
{
    TopologicalSort solution;
    vector<vector<int>> m{{1, 0},

                          };

    bool res = solution.canFinish(2, m);
//    printVector(res);
    cout << "Result: " << res << endl;
}
