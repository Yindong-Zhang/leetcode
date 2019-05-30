//
// Created by so_go on 2019/5/30.
//

#ifndef SRC_KTHSMALLESTINORDEREDMATRIX_H
#define SRC_KTHSMALLESTINORDEREDMATRIX_H
#include<vector>
#include<queue>
#include<functional>
using namespace std;

class KthSmallestInOrderMatrix {
public:
    struct record {
        int value, i, j;
        bool operator>(const record &b) const{
            return value > b.value;
        }
    };

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<record, vector<record>, greater<record>> min_heap;
        int nrows = matrix.size(), ncols = matrix[0].size();
        vector<vector<bool>> visited(nrows, vector<bool>(ncols, false));
        vector<int> res;
        min_heap.push(record{matrix[0][0], 0, 0});
        visited[0][0] = true;
        record min_record;
        for(int it = 0; it < k; it++){
            min_record = min_heap.top();
            min_heap.pop();
            res.push_back(min_record.value);
            if(min_record.i + 1 < nrows && !visited[min_record.i + 1][min_record.j]){
                min_heap.push(record{matrix[min_record.i + 1][min_record.j], min_record.i + 1, min_record.j});
                visited[min_record.i + 1][min_record.j] = true;
            }
            if(min_record.j + 1 < ncols && !visited[min_record.i][min_record.j + 1]){
                min_heap.push(record{matrix[min_record.i][min_record.j + 1], min_record.i, min_record.j + 1});
                visited[min_record.i][min_record.j + 1] = true;
            }

        }
        return res.back();


    }
};
#endif //SRC_KTHSMALLESTINORDEREDMATRIX_H
