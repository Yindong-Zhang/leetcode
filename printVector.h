//
// Created by so_go on 2019/6/11.
//

#ifndef SRC_PRINTVECTOR_H
#define SRC_PRINTVECTOR_H
#include<vector>
#include<iostream>
using namespace std;
template<class T> void printVector(vector<T> vec){
    for(T i:vec){
        cout << i << ' ';
    }
    cout << endl;
}
#endif //SRC_PRINTVECTOR_H
