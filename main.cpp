#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"findword2.h"
using namespace std;

int main()
{
	string s;
    vector<vector<char>> board = {{'a', 'a'}};
    vector<string> words = {"a"};
//    for(auto vec_it = board.begin(); vec_it != board.end(); ++vec_it){
//        for(auto ch_it = vec_it->begin(); ch_it != vec_it->end(); ++ch_it){
//            cout << *ch_it << ' ';
//        }
//        cout << endl;
//    }
    FindWord2 solution;
    vector<string> results;
    results = solution.findWords(board, words);
    for(auto str_it = results.begin(); str_it != results.end(); ++str_it){
        cout << *str_it << endl;
    }
	return 0;

	}
