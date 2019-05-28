//
// Created by so_go on 2019/5/28.
//

#ifndef SRC_MOVEZEROS_H
#define SRC_MOVEZEROS_H
#include<vector>
using namespace std;
class MoveZeors {
public:
    void moveZeroes(vector<int>& nums) {
        int n_zeros= 0;
        for(int i = 0; i < nums.size(); ++i){
            if( !nums[i] ){
                n_zeros++;
                continue;
            }
            else{
                nums[i - n_zeros] = nums[i];
            }
        }
        for(int i = nums.size() - n_zeros; i < nums.size(); ++i){
            nums[i] = 0;
        }

    }
};
#endif //SRC_MOVEZEROS_H
