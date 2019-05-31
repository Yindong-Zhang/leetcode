//
// Created by so_go on 2019/5/31.
//

#ifndef SRC_TOPFREQUENT_H
#define SRC_TOPFREQUENT_H

// unordered_map 计数
//
// 遍历数组， 对应计数器加一， 当计数大于小根堆堆顶，将堆顶弹出，将当前值插入堆中；
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

class TopKFrequent {
public:
    struct entry{
        int value, count;
        bool operator>(const entry &b) const{
            return count > b.count;
        }
        bool operator<(const entry &b) const{
            return count < b.count;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        priority_queue<int, vector<entry>, less<entry>> max_heap;
        vector<int> res;
        for(auto ptr = nums.begin(); ptr != nums.end(); ptr++){
            if(count.find(*ptr) != count.end()){
                count[*ptr]++;
            }
            else{
                count.insert({*ptr, 1});
            }
            // 题目保证至少有k个不同值
        }
        for(auto map_ptr = count.begin(); map_ptr != count.end(); map_ptr++){
            cout << "push: " << map_ptr->first << ' ' << map_ptr->second << endl;
            max_heap.push(entry{map_ptr->first, map_ptr->second});
        }
        for(int i = 0; i < k; i++){
            res.push_back(max_heap.top().value);
            max_heap.pop();
        }
        return res;

    }
};
#endif //SRC_TOPFREQUENT_H
