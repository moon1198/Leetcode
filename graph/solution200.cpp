#include <bits/stdc++.h>

using namespace std;

void recur200_0(vector<vector<char>>& grid, int i, int j) {
    grid[i][j] = '0';
    //up
    if (i > 0 && grid[i - 1][j] == '1') {
        recur200_0(grid, i - 1, j);
    }
    //down
    if (i < grid.size() - 1 && grid[i + 1][j] == '1') {
        recur200_0(grid, i + 1, j);
    }
    //left
    if (j > 0 && grid[i][j - 1] == '1') {
        recur200_0(grid, i, j - 1);
    }
    //right
    if (j < grid[0].size() - 1 && grid[i][j + 1] == '1') {
        recur200_0(grid, i, j + 1);
    }
}

int numIslands(vector<vector<char>>& grid) {
    vector<vector<char>> grid_cp(grid.begin(), grid.end());
    int ans = 0;
    for (int i = 0; i < grid.size(); ++ i) {
        for (int j = 0; j < grid[0].size(); ++ j) {
            if (grid[i][j] == '1') {
                ++ ans;
                recur200_0(grid, i, j);
            }
        }
    }
    return ans;
    
}