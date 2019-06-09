#include<iostream>
#include<string>
#include<vector>
#include<array>
#include"codec.h"
using namespace std;



int main()
{
    Codec solution;
    vector<string> vec{"0", "0", "0", "0", "#", "#", "1", "#", "#", "#", "4"};
    printVector(vec);
    TreeNode *root = solution.buildTree(vec);
    string s =  solution.serialize(root);
    cout << s << endl;
    TreeNode *new_root = solution.deserialize(s);
    string new_s = solution.serialize(new_root);
    cout << new_s << endl;
}
