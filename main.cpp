#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"printVector.h"
#include"medianInTwoSortedArray.h"
using namespace std;



int main()
{
    MedianInTwoSortedArray solution;
//    vector<int> test{2,1,5,6,2,3};
//    string s = "intention", p = "execution";
//    cout << solution.F(15, test, 2) << endl;
//    vector<vector<int>> test{
//            { 1, 2, 3 },
//            { 4, 5, 6 },
//            { 7, 8, 9 }
//    };
//    string a = "123456789", b=  "987654321";
    vector<int> a = {1, 2}, b = {3, 4};
    auto res = solution.findMedianSortedArrays(a, b);
    cout << res << endl;
//    for(auto vec : res){
//        printVector(vec);
//    }
//    printVector(res);
//    cout << "Result: " << res << endl;
}
