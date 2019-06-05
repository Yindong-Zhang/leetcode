//
// Created by yindong on 19-6-3.
//

#ifndef SRC_NESTEDITERATOR_H
#define SRC_NESTEDITERATOR_H
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
#include<vector>
#include<stack>
using namespace std;

class NestedInteger {
    public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
    stack<NestedInteger> s;
    vector<NestedInteger> nlist;
    NestedIterator(vector<NestedInteger> &nestedList) {
        nlist = nestedList;
        for(auto ptr = nlist.rbegin(); ptr != nlist.rend(); ptr++ ){
            s.push(*ptr);
        }

    }

    int next() {
        vector<NestedInteger> tmp;
        int res;
        res = s.top().getInteger();
        s.pop();
        return res;
    }

    bool hasNext() {
        vector<NestedInteger> tmp;
        while(not s.empty() and not s.top().isInteger()){
            tmp = s.top().getList();
            s.pop();
            for(auto ptr = tmp.rbegin(); ptr != tmp.rend(); ptr++){
                s.push(*ptr);
            }

        }
        return not s.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
#endif //SRC_NESTEDITERATOR_H
