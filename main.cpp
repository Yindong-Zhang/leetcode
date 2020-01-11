#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"printVector.h"
#include"waterTrap.h"
using namespace std;



int main()
{
    WaterTrap solution;
    vector<int> test{0,1,0,2,1,0,1,3,2,1,2,1};
    auto res = solution.trap(test);
    cout << "Result: " << res << endl;
}
