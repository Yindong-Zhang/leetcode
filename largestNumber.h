//
// Created by so_go on 2019/6/9.
//

#ifndef SRC_LARGESTNUMBER_H
#define SRC_LARGESTNUMBER_H
#include<string>
#include<vector>
#include<algorithm>


using namespace std;

bool compare(int &a, int &b){
    string sa = to_string(a), sb = to_string(b);
    string s1 = sa + sb;
    string s2 = sb + sa;
    if(s1 > s2){
        return true;
    }
    else{
        return false;
    }
}

class LargestNumber {
public:

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        string res;

        if(nums.front() == 0){
            return "0";
        }
        else{

            for(auto ptr = nums.begin(); ptr != nums.end(); ptr++){
                res.append(to_string(*ptr));
            }
        }
        return res;
    }
};
#endif //SRC_LARGESTNUMBER_H
