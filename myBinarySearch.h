/*
 * myBinarySearch.h
 *
 *  Created on: 2019年4月5日
 *      Author: yindong
 */

#ifndef MYBINARYSEARCH_H_
#define MYBINARYSEARCH_H_
#include<vector>
using namespace std;

struct SearchResult {
	bool whether_find;
	int indice;
};

class Solution {
public:
	SearchResult binary_search(vector<int> array, int key) {
		int a_size = array.size();
		if ( a_size == 0)
			return SearchResult { false, -2 };

		if (key < array[0])
			return SearchResult { false, -1 };
		else if (key == array[0])
			return SearchResult { true, 0 };

		if (array[a_size - 1] < key)
			return SearchResult { false, a_size - 1 };
		else if (key == array[a_size - 1])
			return SearchResult { true, a_size - 1 };

		int low = 0;
		int high = a_size - 1;
		int mid = 0;

		while (high > low + 1) {
			mid = (low + high) / 2;

			if (array[mid] < key)
				low = mid;
			else if (array[mid] > key)
				high = mid;
			else
				return SearchResult { true, mid };
		}
		return SearchResult { false, low };
	}

	vector<int> generate_test_cases() {
		vector<int> test_cases( { 1, 2, 4, 5, 7, 8, 8, 9, 11, 11, 11, 20 });
		return test_cases;
	}
};

#endif /* MYBINARYSEARCH_H_ */
