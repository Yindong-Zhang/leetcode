//
// Created by so_go on 2019/6/20.
//

#ifndef SRC_COUNTPRIME_H
#define SRC_COUNTPRIME_H

#include<cmath>
class CountPrimes {
public:
    int countPrimes(int n) {
        int count = 0;
        if( n < 2){
            return 0;
        }
        vector<bool> isNotPrime(n, false);
        isNotPrime[0] = true;
        isNotPrime[1] = true;
        for(int i = 2; i <= sqrt(n); i++){
            if(isPrime(i)){
                int k = 2;
                while(k * i < n){
                    isNotPrime[k * i] = true;
                    k++;
                }
            }
            else{
                isNotPrime[i] = true;
            }
        }

        for(int i = 0; i< n; i++){
            if(not isNotPrime[i]){
                count++;
            }
        }
        return count;
    }
    // 逐个判断超时
    bool isPrime(int n){
        for(int i = 2; i <= sqrt(n); i++){
            if( n % i == 0){
                return false;
            }
        }
        return true;
    }
};
#endif //SRC_COUNTPRIME_H
