#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"printVector.h"
#include"maxSlidingWindow.h"
using namespace std;



int main()
{
    MaxSlidingWindow solution;
    vector<int> test{7, 2, 4};
    auto res = solution.maxSlidingWindow(test, 2);
//    for(auto vec : res){
//        printVector(vec);
//    }
    printVector(res);
//    cout << "Result: " << res << endl;
}
