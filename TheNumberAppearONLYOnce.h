/*
 * TheNumberAppearONLYOnce.h
 *
 *  Created on: 2019年4月4日
 *      Author: yindong
 */
#ifndef THENUMBERAPPEARONLYONCE_H_
#define THENUMBERAPPEARONLYONCE_H_
#include<vector>
using namespace std;

class Solution{
public:
	int singleNumber(vector<int> &nums){
	    int num= 0;
	    for(unsigned int i = 0; i < nums.size(); i++)
	    {
	        num = num ^ nums[i];
	    }
	    return num;

	};
	vector<int> generate_test_cases(){
		vector<int> x{{1, 2, 3, 1, 2}};
		return x;
	};
};



#endif /* THENUMBERAPPEARONLYONCE_H_ */
