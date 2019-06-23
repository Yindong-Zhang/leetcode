//
// Created by so_go on 2019/6/23.
//

#ifndef SRC_GETSKYLINE_H
#define SRC_GETSKYLINE_H

#include<vector>
#include<set>
#include<functional>
#include<algorithm>
#include<iostream>
#include"printVector.h"
using namespace std;

struct Record{
    int pos, height;
    friend ostream & operator<<(ostream & os, const Record & r){
        os << r.pos << ':' << r.height;
        return os;
    }
    bool operator<(const Record & b) const{
        return pos < b.pos;
    }
};
class GetSkyLine {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<int> s{0, };
        vector<Record> vec;
        vector<vector<int>> res;
        for(int i = 0; i < buildings.size(); i++){
            // left height
            vec.push_back(Record{buildings[i][0], buildings[i][2]});
            // right height
            vec.push_back(Record{buildings[i][1], -buildings[i][2]});
        }
        sort(vec.begin(), vec.end());
        printVector(vec);
        int lastPos, oldMax;
        auto ptr = vec.begin();
        while(ptr != vec.end()){
            oldMax = *s.rbegin();
            do{
                if(ptr->height > 0){
                    s.insert(ptr->height);
                }
                else{
                    s.erase(s.find(-ptr->height));
                }
                lastPos = ptr->pos;
                ptr++;
            }
            while(ptr != vec.end() and ptr->pos == lastPos);

            if(*s.rbegin() != oldMax){
                res.push_back({lastPos, *s.rbegin()});
            }

//           for(auto stPtr = s.begin(); stPtr != s.end(); stPtr++){
//                cout << *stPtr << ' ';
//            }
//            cout << endl;
        }
        return res;
    }
};
#endif //SRC_GETSKYLINE_H
