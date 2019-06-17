//
// Created by so_go on 2019/6/16.
//

#ifndef SRC_PRINTMATRIX_H
#define SRC_PRINTMATRIX_H
#include<vector>
#include<iostream>
using namespace std;
template <class T> void printMatrix(vector<vector<T>> m){
    for(int i = 0; i < m.size(); i++){
        for(int j = 0; j < m[i].size(); j++){
            cout << m[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}
#endif //SRC_PRINTMATRIX_H
