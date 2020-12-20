//
// Created by so_go on 2020/12/15.
//

#ifndef SRC_MONOTONEINCREASINGDIGITS__738_H
#define SRC_MONOTONEINCREASINGDIGITS__738_H
#include<bits/stdc++.h>
using namespace std;

class MonoIncreasingDigits {
        public:
        int monotoneIncreasingDigits(int N) {
            vector<int> digits;
            int n = N;
            while(n > 0){
                int d = n % 10;
                digits.push_back(d);
                n /= 10;
            }
            stack<int> st;
            int i = digits.size() - 1;
            while(i > 0) {
                if (digits[i - 1] >= digits[i]) {
                    st.push(digits[i]);
                    --i;
                }
                else{
                    break;
                }
            }
            if(i == 0) {
                st.push(digits[0]);
            }
            else {
                int curNum = digits[i];
                while (not st.empty() and st.top() > curNum - 1) {
                    curNum = st.top();
                    st.pop();
                    ++i;
                }
                st.push(curNum - 1);
                --i;
                while (i >= 0) {
                    st.push(9);
                    i--;
                }
            }
            int ret = 0;
            int base = 1;
            while(not st.empty()){
                cout << st.top() << endl;
                ret += st.top() * base;
                base = base * 10;
                st.pop();
            }
            return ret;
        }
};
#endif //SRC_MONOTONEINCREASINGDIGITS__738_H
