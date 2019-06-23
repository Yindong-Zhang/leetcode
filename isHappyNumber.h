//
// Created by so_go on 2019/6/23.
//

#ifndef SRC_ISHAPPYNUMBER_H
#define SRC_ISHAPPYNUMBER_H

#include<cmath>
#include<unordered_set>
using namespace std;
class IsHappy {
public:
    bool isHappy(int n) {
        unordered_set<int> encounter;
        while( n != 1){
            cout << n << endl;
            if(encounter.find(n) != encounter.end()){
                // if find
                break;
            }
            else{
                // not find
                encounter.insert(n);
            }
            n = transform(n);
        }
        if(n == 1){
            return true;
        }
        else{
            return false;
        }
    }

    int transform(int n){
        int res = 0;
        int tmp;
        while( n > 0){
            tmp = n % 10;
            res  += tmp * tmp;
            n = n / 10;
        }
        return res;
    }
};
#endif //SRC_ISHAPPYNUMBER_H
