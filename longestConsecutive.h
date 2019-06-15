//
// Created by so_go on 2019/6/15.
//

#ifndef SRC_LONGESTCONSECUTIVE_H
#define SRC_LONGESTCONSECUTIVE_H
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;
class LongestConsecutive {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        auto pos = m.end(), left = m.end(), right = m.end();
        int lv, rv;
        for(auto ptr = nums.begin(); ptr != nums.end(); ptr++){
            pos = m.find(*ptr);
            if( pos == m.end()){
                // 如果该数字没有出现过
                left = m.find(*ptr - 1);
                right = m.find(*ptr + 1);
                if( left == m.end() and right == m.end()){
                    //当左右数字都还没出现过：
//                    cout << *ptr << ' ' << 1 << endl;
                    m.insert({*ptr, 1});
                }
                else if( left != m.end() and right == m.end()){
                    // 当a[i - 1]非空
//                    cout << *ptr << ' ' << *ptr - left->second << ' ' << left->second + 1 << endl;
                    lv = left->second;
                    m.insert({*ptr, lv + 1});
                    m[*ptr - lv] = lv + 1;
                }
                else if( left == m.end() and right != m.end()){
                    // 当a[i + 1] 非空
                    // cout << *ptr << ' ' << *ptr + right->second  << ' ' << right->second + 1 << endl;
                    rv = right->second;
                    m.insert({*ptr, rv + 1});
                    m[*ptr + rv] = rv + 1;
                }
                else{
                    // a[i - 1] 和 a[i + 1] 均非空
//                    cout << *ptr - left->second << ' ' << *ptr + right->second << ' ' << 1 + left->second + right->second << endl;
                    lv = left->second;
                    rv = right->second;
                    m.insert({*ptr, 1});
                    m[*ptr - lv] = 1 + lv + rv;
                    m[*ptr + rv] = 1 + lv + rv;
                }

            }

        }
        // 遍历字典，寻找最大值
        int max = 0;
        for(auto ptr = m.begin(); ptr != m.end(); ptr++){
//            cout << ptr->second << endl;
            if(ptr->second > max){
                max = ptr->second;
            }
        }
        return max;
    }
};
#endif //SRC_LONGESTCONSECUTIVE_H
