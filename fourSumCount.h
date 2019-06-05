//
// Created by so_go on 2019/6/5.
//

#ifndef SRC_FOURSUMCOUNT_H
#define SRC_FOURSUMCOUNT_H
#include<unordered_map>
#include<vector>
using namespace std;

class FourSumCount {
public:

    unordered_map<int, int> count0, count1;
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int sum;
        for(int i = 0; i < A.size(); i++)
            for(int j = 0; j < B.size(); j++){
                sum = A[i] + B[j];
                auto ptr = count0.find(sum);
                if(ptr == count0.end()){
                    count0.insert({sum, 1});
                }
                else{
                    (ptr->second)++;
                }
            }

        for(int i = 0; i < C.size(); i++)
            for(int j = 0; j < D.size(); j++){
                sum = C[i] + D[j];
                auto ptr = count1.find(sum);
                if(ptr == count1.end()){
                    count1.insert({sum, 1});
                }
                else{
                    (ptr->second)++;
                }
            }

        int res = 0;
        for(auto ptr0 = count0.begin(); ptr0 != count0.end(); ptr0++){
            auto ptr1 = count1.find(-ptr0->first);
            if(ptr1 != count1.end()){
                res += ptr0->second * ptr1->second;
            }
        }
        return res;
    }
};
#endif //SRC_FOURSUMCOUNT_H
