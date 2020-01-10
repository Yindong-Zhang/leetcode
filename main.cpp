#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"printVector.h"
#include"stockChangeIII.h"
using namespace std;



int main()
{
    StockChange solution;
    vector<int> prices{7,6,4,3,1};
    auto res = solution.maxProfit(prices);
    cout << "Result: " << res << endl;
}
