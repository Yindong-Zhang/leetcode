/*
 * majorityNumber.h
 *
 *  Created on: 2019年4月5日
 *      Author: yindong
 */

#ifndef MAJORITYNUMBER_H_
#define MAJORITYNUMBER_H_

#include<vector>
using namespace std;
struct SearchResult {
	bool whether_find;
	int indice;
};

class MajorityElement {
public:
    int majorityElement(vector<int>& nums) {
        int candidate, count = 0;
        for(unsigned int i = 0; i < nums.size(); i++)
        {
        	if(0 == count){
        		candidate = nums[i];
        	    count++;
        	}
        	else if(nums[i] != candidate)
        		count--;
        	else
        		count++;
        }
        return candidate;
    }

    vector<int> generate_test_cases(){
    	vector<int> test_cases({4, 4, 3, 3, 4, 3, 3, 3, 5, 4, 4, 4, 4, 4});
    	return test_cases;
    }
};



#endif /* MAJORITYNUMBER_H_ */
