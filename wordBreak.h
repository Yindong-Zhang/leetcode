/*
 * wordbreak.h
 *
 *  Created on: May 23, 2019
 *      Author: yindong
 */

#ifndef WORDBREAK_H_
#define WORDBREAK_H_

#include<string>
#include<vector>
#include<iostream>
#include<array>
using namespace std;

class WordBreak {
public:
    //    定义break[i]为前i位是否可拆分的bool数组， 默认空字符串可拆分，即break[0] = 1
    //    break[i] = OR{ break[j] and match(string[j:i)) for j in range[0, i)

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> breakable;
        breakable.push_back(true);
        for(unsigned int i = 1; i <= s.size(); i++){
            bool tmp = false;
            for( unsigned int j = 0; j < i; j++){
                if(breakable[j] && match(s, j, i, wordDict)){
                    tmp = true;
                    break;
                }
            }
            breakable.push_back(tmp);
        }
        return breakable.back();
    }

    bool match(string &s, int start, int end, const vector<string> &wordDict){
        string word;
        for(int i = 0; i < wordDict.size(); i++){
            word = wordDict[i];
            bool ismatch = true;
            if( word.size() != ( end - start ) ){
                ismatch = false;
            }
            else{
                for(int j = 0; j < word.size(); j++)
                    if( word[j] !=  s[start + j] )
                        ismatch = false;
            }

            if(ismatch)
                return true;
        }
        return false;
    }
//  超时
/*
    bool wordBreak_(string &s, int ind, const vector<string> &wordDict){
    	if(ind == s.size())
    		return true;
    	string word;
    	for(int i = 0; i < wordDict.size(); i++){
    		word = wordDict[i];
    		if(match(s, ind, word)){
//    		    cout << s << ' ' << ind << ' ' << word << endl;
    			if(wordBreak_(s, ind + word.size(), wordDict))
    				return true;
    		}
    	}
    	return false;
    }

    bool match(string &s, int start, string &word){
    	if(start + word.size() <= s.size()){
    		for(int i = 0; i < word.size(); i++){
    			if(word[i] != s[start + i])
    				return false;
    		}
    	}
    	else
    		return false;
    	return true;
    }
    */
};



#endif /* WORDBREAK_H_ */
