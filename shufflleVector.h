//
// Created by so_go on 2019/5/28.
//

#ifndef SRC_SHUFFLLEVECTOR_H
#define SRC_SHUFFLLEVECTOR_H

#include<vector>
#include<cstdlib>
using namespace std;
class ShuffleVector {
public:
    vector<int> vec;
    ShuffleVector(vector<int>& nums) {
        vec = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return vec;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res(vec);
        int choice;
        int tmp;
        for(int i = 0; i < res.size(); ++i){
            // 产生一个[0, range) 内随机整数i， 交换 res[i] 和 res[range - 1]
            choice = rand() % (res.size() - i);
            cout << choice << endl;
            tmp = res[choice];
            res[choice] = res[res.size() - i - 1];
            res[res.size() - i - 1] = tmp;

        }
        return res;

    }
};
#endif //SRC_SHUFFLLEVECTOR_H
