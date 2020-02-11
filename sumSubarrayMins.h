//
// Created by so_go on 2020/2/11.
//
/* 907
 * 给定一个整数数组 A，找到 min(B) 的总和，其中 B 的范围为 A 的每个（连续）子数组。

由于答案可能很大，因此返回答案模 10^9 + 7。



示例：

输入：[3,1,2,4]
输出：17
解释：
子数组为 [3]，[1]，[2]，[4]，[3,1]，[1,2]，[2,4]，[3,1,2]，[1,2,4]，[3,1,2,4]。
最小值为 3，1，2，4，1，1，2，1，1，1，和为 17。



提示：

    1 <= A <= 30000
    1 <= A[i] <= 30000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-subarray-minimums
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#ifndef SRC_SUMSUBARRAYMINS_H
#define SRC_SUMSUBARRAYMINS_H
#include<vector>
#include<stack>
#include"printVector.h"
#define M 1000000007
using namespace std;
// 单调栈 解决 为每个数查找数组左边小于当前数的第一个位置， 右边小于当前数的第一个位置
// 单调栈/队列：当新的数大于栈中的对象，栈中已有的对象就失去意义，可以弹出。
class SumSubArrayMins {
public:
    int sumSubarrayMins(vector<int>& A) {
        vector<int> l(A.size(), 0), r(A.size(), 0);
        stack<int> st_l;
        for(int i = 0; i < A.size(); i++){
            while(not st_l.empty() and A[st_l.top()] > A[i]){
                st_l.pop();
            }
            if(st_l.empty()){
                l[i] = -1;
            }
            else{
                l[i] = st_l.top();
            }
            st_l.push(i);
        }
        stack<int> st_r;
        for(int j = A.size() - 1; j >= 0; j--){
            while(not st_r.empty() and A[st_r.top()] >= A[j]){
                st_r.pop();
            }
            if(st_r.empty()){
                r[j] = A.size();
            }
            else{
                r[j] = st_r.top();
            }
            st_r.push(j);
        }
        printVector(l);
        printVector(r);
        int res = 0;
        for(int i = 0; i < A.size(); i++){
            res = (res + (A[i] * (r[i] - i) * (i - l[i])) % M) % M;
        }
        return res;
    }
};
#endif //SRC_SUMSUBARRAYMINS_H
