//
// Created by so_go on 2019/6/9.
//

#ifndef SRC_LARGESTNUMBER_H
#define SRC_LARGESTNUMBER_H
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
class LargestNumber {
public:
    // TODO:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        string res;
        for(auto i : nums){
            res.append(to_string(i));
        }
        return res;
    }
};
#endif //SRC_LARGESTNUMBER_H
