//
// Created by so_go on 2019/6/17.
//

#ifndef SRC_NUMISLANDS_H
#define SRC_NUMISLANDS_H
#include<vector>
using namespace std;

class NumIslands {
public:
    void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &visited){
        int nrows = grid.size(), ncols = grid[0].size();
        visited[i][j] = true;
        if(i + 1 < nrows and grid[i + 1][j] == '1' and not visited[i + 1][j]){
            dfs(i + 1, j, grid, visited);
        }
        if(i - 1 >= 0 and grid[i - 1][j] == '1' and not visited[i - 1][j]){
            dfs(i - 1, j, grid, visited);
        }
        if( j + 1 < ncols and grid[i][j + 1] == '1' and not visited[i][j + 1]){
            dfs(i, j + 1, grid, visited);
        }
        if( j - 1 >= 0 and grid[i][j - 1] == '1' and not visited[i][j - 1]){
            dfs(i, j - 1, grid, visited);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0){
            return 0;
        }
        int nrows = grid.size(), ncols = grid[0].size();
        int count = 0;
        bool finished = true;
        int row = -1, col = -1;
        for(int i = 0; i < nrows * ncols; i++){
            row = i / ncols;
            col = i % ncols;
            if(grid[row][col] == '1'){
                finished = false;
                break;
            }
        }
        vector<vector<bool>> visited(nrows, vector<bool>(ncols, false));
        while(not finished){
            cout << row << ' ' << col << endl;
            dfs(row, col, grid, visited);
            count++;

            finished = true;
            for(int i = 0; i < nrows * ncols; i++){
                row = i / ncols;
                col = i % ncols;
                if(grid[row][col] == '1' and not visited[row][col]){
                    finished = false;
                    break;
                }
            }

        }
        return count;
    }
};
#endif //SRC_NUMISLANDS_H
