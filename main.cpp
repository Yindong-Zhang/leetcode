#include<iostream>
#include<string>
#include<vector>
#include"wordBreak2.h"
using namespace std;

int main()
{
	string s;
	WordBreak2 solution;
	vector<string> wordDict;
    vector<string> results;

	cout << "test_case: " << endl;
	cin >> s;
	cout << s << endl;

	string word;
	cout << "Enter word dict: " << endl;
	while(cin >> word)
	{
		wordDict.push_back(word);
	}

	for(int i = 0; i < wordDict.size(); i++)
		cout << wordDict[i] << ' ';
	cout << endl;

	results = solution.wordBreak2(s, wordDict);
	for(int i = 0; i < results.size(); ++i){
        cout << results[i] <<  endl;
    }

	return 0;

	}
