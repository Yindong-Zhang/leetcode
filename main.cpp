#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"printVector.h"
#include"spiralMatrix_54.h"
using namespace std;



int main()
{
    SpiralMatrix solution;
//    vector<int> test{2,1,5,6,2,3};
//    string s = "intention", p = "execution";
//    cout << solution.F(15, test, 2) << endl;
    vector<vector<int>> test{
            { 1, 2, 3 },
            { 4, 5, 6 },
            { 7, 8, 9 }
    };
    auto res = solution.spiralOrder(test);
//    cout << res << endl;
//    for(auto vec : res){
//        printVector(vec);
//    }
    printVector(res);
//    cout << "Result: " << res << endl;
}
