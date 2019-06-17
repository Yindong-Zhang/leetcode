#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"ladderlength.h"
using namespace std;



int main()
{
    LadderLength solution;
    vector<string> m{"hot", "dot", "dog", "lot", "log", "cog"};

    int res = solution.ladderLength("hit", "cog", m);
//    printVector(res);
    cout << "Result: " << res << endl;
}
