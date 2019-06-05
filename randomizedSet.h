//
// Created by so_go on 2019/6/5.
//

#ifndef SRC_RANDOMIZEDSET_H
#define SRC_RANDOMIZEDSET_H
#include<vector>
#include<unordered_map>
using namespace std;

class RandomizedSet {
public:
    unordered_map<int, int> val2ind;
    vector<int> val_list;
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {

        auto res = val2ind.insert({val, val2ind.size()});
        if(res.second){
            val_list.push_back(val);
        }
        return res.second;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        int tmp;
        auto ptr = val2ind.find(val);
        if(ptr == val2ind.end()){
            return false;
        }
        else{
            tmp = val_list.back();
            val_list[ptr->second] = tmp;
            val_list.pop_back();
            val2ind[tmp] = ptr->second;
            val2ind.erase(ptr);
            return true;
        }
    }

    /** Get a random element from the set. */
    int getRandom() {
        if(val_list.size() == 0){
            return NULL;
        }
        int ind = rand() % val_list.size();
        return val_list[ind];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
#endif //SRC_RANDOMIZEDSET_H
