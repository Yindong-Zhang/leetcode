/*
 * partitionPalindrome.h
 *
 *  Created on: 2019年4月11日
 *      Author: yindong
 */

#ifndef PARTITIONPALINDROME_H_
#define PARTITIONPALINDROME_H_

#include<vector>
#include<string>
using namespace std;

class PartitionPalindrome{
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> results;
        vector<string> res;
        partition_(s, 0, res, results);
        return results;
    }

    int partition_(const string &s, int ind, vector<string> res, vector<vector<string>> &results){
//    	停止条件
    	if (ind == s.size()){
    		results.push_back(res);
    	}
//    	递归过程
    	for(int i = 1; i <= s.size() - ind; i++ ){
    		if(isPalindrome(s.substr(ind, i))){
    			res.push_back(s.substr(ind, i));
    			partition_(s, ind + i, res, results);
				res.pop_back();
    		}
    	}
    	return 1;
    }

    bool isPalindrome(string s) {
        	if (s.size() == 0)
        		return true;

        	string s_st;
        	for (unsigned int i = 0; i < s.size(); i++){
        			if (isalnum(s[i])){
        				s_st.push_back(tolower(s[i]));
//        				cout<< s[i] << endl;
        			}
        	}
    //    	cout << "new string: " << s_st << endl;
        	int left = 0, right = s_st.size() - 1;
        	while(left < right){
    //    		cout << '\t' << left << ": " << s[left] << '\t' << right << ": " << s[right] << endl;
        		if ( not ( s_st[left++] == s_st[right--] ) )
        			return false;
        	}
        	return true;
        }
};



#endif /* PARTITIONPALINDROME_H_ */
