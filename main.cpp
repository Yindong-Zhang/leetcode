#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"printVector.h"
#include"russianDollEnvelops.h"
using namespace std;



int main()
{
    russianDollEnvelops solution;
    vector<vector<int>> test{{4,5},{4,6},{6,7},{2,3},{1,1}};
    auto res = solution.maxEnvelopes(test);
    cout << "Result: " << res << endl;
}
