#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"printVector.h"
#include"permute.h"
using namespace std;



int main()
{
    Permute solution;
    vector<int> test{1,2,3};
    auto res = solution.permute(test);
    for(auto vec : res){
        printVector(vec);
    }
//    cout << "Result: " << res << endl;
}
