/*
 * mergeSorted.h
 *
 *  Created on: 2019年4月6日
 *      Author: yindong
 */

#ifndef MERGESORTED_H_
#define MERGESORTED_H_

#include<vector>
#include<algorithm>
using namespace std;

struct TestCase{
	vector<int> nums1, nums2;
	int m, n;
};
class MergeSortedSolution{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (unsigned int i = m; i < m + n; i++)
        	nums1[i] = nums2[ i - m ];
        sort(nums1.begin(), nums1.begin() + m + n);
        for(unsigned int i = 0; i < m + n; i++)
        	cout << nums1[i] << '\t';
        cout << endl;
    }

    TestCase generate_test_cases(){
    	vector<int> nums1({1,2,3,0,0,0}), nums2({2,5,6});
    	int m = 3, n = 3;
    	return TestCase{nums1, nums2, m, n};
    }
};


#endif /* MERGESORTED_H_ */
