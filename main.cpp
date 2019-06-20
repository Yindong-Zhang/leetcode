#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"printVector.h"
#include"countPrime.h"
using namespace std;



int main()
{
    CountPrimes solution;
    auto res = solution.countPrimes(2);
//    printVector(res);
    cout << "Result: " << res << endl;
}
