#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"printVector.h"
#include"getSkyLine.h"
using namespace std;



int main()
{
    GetSkyLine solution;
    vector<vector<int>> box{ {0, 1, 3}};

    auto res = solution.getSkyline(box);
    for(auto ptr = res.begin(); ptr != res.end(); ptr++){
        printVector(*ptr);

    }
//    cout << "Result: " << res << endl;
}
