#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"wiggleSort.h"
#include"printVector.h"
using namespace std;



int main()
{
    WiggleSort solution;
    vector<int> vec{1, 1, 2, 1, 2, 2, 1};
    cout << "Before sort: " << endl;
    printVector(vec);
    solution.wiggleSort2(vec);
    cout << "After sort: " << endl;
    printVector(vec);
}
