//
// Created by so_go on 2019/6/14.
//

#ifndef SRC_COUNTSMALLER_H
#define SRC_COUNTSMALLER_H
#include<vector>
#include"printVector.h"
using namespace std;

class CountSmaller {
public:
    vector<int> countSmaller(vector<int>& nums) {
        // 从尾开始的插入排序,从尾开始升序排序, 也就是从当前位置降序排列
        // 倒序遍历数组，对于当前位置j 数字n
        // 遍历后数组查找插入位置 nums[i] >= n > nums[i + 1]， i > j
        // (j, i]数组前移一位， nums[i] = n,
        int it, j;
        int tmp;
        vector<int> count(nums.size(), 0);
        for(it = nums.size() - 2; it >= 0; it--){
            tmp = nums[it];
            j = it + 1;
            while( j < nums.size() and nums[j] >= tmp){
                j++;
            }
            count[it] = nums.size() - j;
            // j = i + 1
            for(int k = it + 1; k < j; k++){
                nums[k - 1] = nums[k];
            }
            nums[ j - 1] = tmp;
            printVector(nums);
            cout << count[it] << endl;
        }
        return count;
    }
};
#endif //SRC_COUNTSMALLER_H
