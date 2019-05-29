//
// Created by so_go on 2019/5/29.
//

#ifndef SRC_FINDKTHLARGEST_H
#define SRC_FINDKTHLARGEST_H
#include<vector>
#include<list>
#include<algorithm>
#include<iostream>
using namespace std;
class FindKthLargest {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /*
         * 类似于部分排序
         */
        list<int> k_lgst(nums.begin(), nums.begin() + k);
        k_lgst.sort();
        for(auto ptr = nums.begin() + k; ptr != nums.end(); ++ptr) {
            auto lst_ptr = k_lgst.begin();
            if (*ptr >= *lst_ptr) {
                lst_ptr++;
                while (*ptr > *lst_ptr && lst_ptr != k_lgst.end()) {
                    lst_ptr++;
                }
                k_lgst.insert(lst_ptr, *ptr);
                k_lgst.erase(k_lgst.begin());
                for (auto it = k_lgst.begin(); it != k_lgst.end(); ++it) {
                    cout << *it << ' ';
                }
                cout << endl;
            }
        }
        return k_lgst.front();

    }
};
#endif //SRC_FINDKTHLARGEST_H
