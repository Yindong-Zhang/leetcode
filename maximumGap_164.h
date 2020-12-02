//
// Created by so_go on 2020/11/26.
//

#ifndef SRC_MAXIMUMGAP_164_H
#define SRC_MAXIMUMGAP_164_H
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2){
            return 0;
        }
        int min_num = INT_MAX, max_num = INT_MIN;
        for(int num: nums){
            min_num = min(min_num, num);
            max_num = max(max_num, num);
        }
        // cout << max_num << ' ' << min_num << endl;
        int tmp = (max_num - min_num) / (nums.size() - 1);
        int box_width = max(tmp,  1);
        // cout << box_width << endl;
        int cnt = (max_num - min_num) / box_width + 1;
        // cout << cnt << endl;
        vector<int> box_max(cnt, -1);
        vector<int> box_min(cnt, -1);
        for(int num: nums){
            int index = (num - min_num) / box_width;
            // cout << index << endl;
            if(-1 == box_max[index] or num > box_max[index]){
                box_max[index] = num;
            }
            if(-1 == box_min[index] or num < box_min[index]){
                box_min[index] = num;
            }
        }
        // for(int i = 0; i < cnt; ++i){
        //     cout << box_max[i] << ' ';
        // }
        // cout << endl;
        int res = 0;
        int last_max = -1;
        for(int i = 0; i < cnt; ++i){
            if(box_min[i] != -1){
                if(last_max != -1){
                    res = max(res, box_min[i] - last_max);
                }
                last_max = box_max[i];
            }
        }
        return res;
    }
};
#endif //SRC_MAXIMUMGAP_164_H
