//
// Created by so_go on 2019/5/27.
//

#ifndef SRC_FIRSTUNIQUECHAR_H
#define SRC_FIRSTUNIQUECHAR_H
#include<string>
#include<array>
#include<limits>
using namespace std;
class FirstUniqChar {
public:
    // 记录第一次出现位置 数组， 记录出现次数
    int firstUniqChar(string s) {
        array<int ,26> count;
        array<int, 26> first_apr;
        count.fill(0);
        first_apr.fill(-1);
        int ord;
        for(int i = 0; i < s.size(); ++i){
            ord = s[i] - 'a';
            count[ord] += 1;
            if( first_apr[ord] == -1){
                first_apr[ord] = i;
            }
        }

        int min_pos = s.size();
        for(int j = 0; j < 26; ++j){
            if(count[j] == 1){
                if(first_apr[j] < min_pos){
//                    cout << j << ' ' << first_apr[j] << ' ' << min_pos << endl;
                    min_pos = first_apr[j];
                }
            }
        }
        if(min_pos == s.size())
            return -1;
        else
            return min_pos;
    }
};
#endif //SRC_FIRSTUNIQUECHAR_H
