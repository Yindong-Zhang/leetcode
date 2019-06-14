#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"kRepeatedLongestSubstring.h"
#include"printVector.h"
using namespace std;



int main()
{
    KRepeatedLongestSubstring solution;
    string s("bbaaacbd");
    int res = solution.longestSubstring(s, 3);
//    printVector(res);
    cout << "Result: " << res << endl;
}
