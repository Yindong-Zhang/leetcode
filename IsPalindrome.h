/*
 * IsPalindrome.h
 *
 *  Created on: 2019年4月10日
 *      Author: yindong
 */

#ifndef ISPALINDROME_H_
#define ISPALINDROME_H_
#include<string>
#include<cctype>
using namespace std;

class IsPalindromeSolution {
public:
    static bool isPalindrome(string s) {
    	if (s.size() == 0)
    		return true;

    	string s_st;
    	for (unsigned int i = 0; i < s.size(); i++){
    			if (isalnum(s[i])){
    				s_st.push_back(tolower(s[i]));
    				cout<< s[i] << endl;
    			}
    	}
//    	cout << "new string: " << s_st << endl;
    	int left = 0, right = s_st.size() - 1;
    	while(left < right){
//    		cout << '\t' << left << ": " << s[left] << '\t' << right << ": " << s[right] << endl;
    		if ( s_st[left++] != s_st[right--] )
    			return false;
    	}
    	return true;
    }
};



#endif /* ISPALINDROME_H_ */
