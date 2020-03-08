#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"printVector.h"
#include"minCostTickets_983.h"
using namespace std;



int main()
{
    MinCostTickets solution;
    vector<int> days = {1,4,6,7,8,20}, costs = {2,7,15};
    auto res = solution.mincostTickets(days, costs);
    cout << res << endl;
//    for(auto vec : res){
//        printVector(vec);
//    }
//    printVector(res);
//    cout << "Result: " << res << endl;
}
