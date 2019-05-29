#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"findKthLargest.h"
using namespace std;

int main()
{
    FindKthLargest solution;
    vector<int> vec{1, 2, 4, -2, 5, 6};
    cout << solution.findKthLargest(vec, 5) << endl;

}
