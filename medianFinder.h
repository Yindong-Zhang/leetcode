//
// Created by so_go on 2019/5/29.
//

#ifndef SRC_MEDIANFINDER_H
#define SRC_MEDIANFINDER_H
#include<vector>
#include<queue>
#include<functional>
using namespace std;

class MedianFinder {
private:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, less<int>> max_heap; // 大顶堆
    priority_queue<int, vector<int>, greater<int>> min_heap; // 小顶堆
public:
    void addNum(int num) {
        int tmp;
        if( max_heap.size() == 0 && min_heap.size() == 0){
            max_heap.push(num);
        }
        else {
            if(num < max_heap.top()){
                max_heap.push(num);
                if( max_heap.size() - min_heap.size() > 1){
                    tmp = max_heap.top();
                    max_heap.pop();
                    min_heap.push(tmp);
                }
            }
            else{
                min_heap.push(num);
                if( min_heap.size() - max_heap.size() > 1){
                    tmp = min_heap.top();
                    min_heap.pop();
                    max_heap.push(tmp);
                }
            }
        }
//        cout << max_heap.size() << ' ' << min_heap.size() << endl;
    }

    double findMedian() {
        if(min_heap.size() == max_heap.size()){
            return (min_heap.top() + max_heap.top())/2.0;
        }
        else{
            return min_heap.size() > max_heap.size() ? min_heap.top() : max_heap.top();
        }

    }
};
#endif //SRC_MEDIANFINDER_H
