#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"isAnagram.h"
using namespace std;

int main()
{
	string s, t;

	cin >> s >> t;
	IsAnaGram solution;
    bool results = solution.isAnagram(s, t);
    cout << results;
	return 0;

	}
