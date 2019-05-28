#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"moveZeros.h"
using namespace std;

int main()
{
	vector<int> nums;
	int n;
    cout << "Input vector: " << endl;
    while(cin >> n){
        nums.push_back(n);
    };
    for(int i : nums){
        cout << i << ' ';
    }
    cout << endl;
	MoveZeors solution;
    solution.moveZeroes(nums);
    for(int i : nums){
        cout << i << ' ';
    }
    cout << endl;
	return 0;

	}
