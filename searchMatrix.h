/*
 * searchMatrix.h
 *
 *  Created on: 2019年4月5日
 *      Author: yindong
 */

#ifndef SEARCHMATRIX_H_
#define SEARCHMATRIX_H_
#include<vector>
#include<iostream>
using namespace std;

struct SearchResult{
	bool whether_find;
	int indice;
};

class SearchMatrixSolution {
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

    bool search_matrix(vector<vector<int>>& matrix, int target) {
    	if ( ( matrix.size() == 0 ) || (matrix[0].size() == 0 ) )
    		return false;
    	unsigned int nrows = matrix.size(), ncols = matrix[0].size();
    	unsigned int left = 0, top = 0, right = ncols - 1, bottom = nrows - 1;
    	while (( left < right ) && ( top < bottom )){

    		unsigned int max_col = right;
    		if ( target < matrix[top][left] )
    			return false;
    		for(unsigned int i = left; i < right; i++){
    			if ( target == matrix[top][i] )
    				return true;
    			else if ( ( matrix[top][i] < target ) && ( target < matrix[top][i + 1 ]) ){
    				max_col = i;
    				break;
    			}
    		}
    		if ( target == matrix[top][right])
    			return true;
    		right = max_col;

    		unsigned int min_col = left;
    		if ( target > matrix[bottom][right])
    			return false;
    		for (unsigned int i = right ; i > left; i-- ){
    			if ( target == matrix[bottom][i])
    				return true;
    			else if (( matrix[bottom][i - 1] < target ) && ( target < matrix[bottom][i])){
    				min_col = i;
    				break;
    			}
    		}
    		if ( target == matrix[bottom][left])
    			return true;

    		left = min_col;

    		unsigned int max_row = bottom;
    		if (target < matrix[top][left])
    			return false;
    		for (unsigned int i = top; i < bottom; i ++){
    			if (target == matrix[i][left])
    				return true;
    			else if ( ( matrix[i][left] < target ) && ( target < matrix[i + 1][left] ) ){
    				max_row = i;
    				break;
    			}
    		}
    		if (target == matrix[bottom][left])
    			return true;

    		bottom = max_row;

    		unsigned int min_row = top;
    		if ( target > matrix[bottom][right])
    			return false;
    		for ( unsigned int i = bottom; i > top; i -- ){
    			if (target == matrix[i][right])
    				return true;
    			else if ( ( matrix[i - 1][right] < target ) && ( target < matrix[i][right] )){
    				min_row = i;
    				break;
    			}
    		}
    		if (target == matrix[top][right])
    			return true;

    		top = min_row;


    	}

    	if ( ( bottom == top ) && ( left == right ) )
    		return (matrix[bottom][left] == target);
    	else if ( (bottom == top) && (left != right ) ){
    		for (int i = left; i <= right; i ++ ){
    		    if (target == matrix[bottom][i])
    		    	return true;
    		}
    		return false;
    	}
    	else if ( ( left == right ) && ( bottom != top ) ){
    		for (int i = top; i <= bottom; i++)
    		{
    			if ( target == matrix[i][left] )
    				return true;
    		}
    		return false;

    	}
    	return false;
    }

    vector<vector<int>> generate_test_cases(){
    	vector<vector<int>> test_cases{{1,   4,  7, 11, 15},
    		  {2,   5,  8, 12, 19},
    		  {3,   6,  9, 16, 22},
    		  {10, 13, 14, 17, 24},
			  {18, 21, 23, 26, 30}};
    	return test_cases;
    }
};



#endif /* SEARCHMATRIX_H_ */
