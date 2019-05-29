//
// Created by so_go on 2019/5/29.
//

#ifndef SRC_LISTINTERSECT_H
#define SRC_LISTINTERSECT_H
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

class Intersect {
public:
    // min(a, b) = a - b > 0 ? b : a;
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> ncounts;
        vector<int> results;
        for(int n : nums1){
            if(ncounts.find(n) != ncounts.end()){
                ncounts[n] += 1;
            }
            else{
                ncounts[n] = 1;
            }
        }
        for(int n : nums2){
            if(ncounts.find(n) != ncounts.end()){
                if(ncounts[n] > 0){
                    ncounts[n]--;
                    results.push_back(n);
                }
            }
        }
        return results;
    }
};
#endif //SRC_LISTINTERSECT_H
