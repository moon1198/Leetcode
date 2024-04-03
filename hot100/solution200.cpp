#include <bits/stdc++.h>
using namespace std;

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

void recur(vector<vector<char>>& grid, int i, int j) {
    int m = grid.size();
    int n = grid[0].size();
    for (int k = 0; k < 4; ++ k) {
        int nextx = i + dir[k][0];
        int nexty = j + dir[k][1];
        if (nextx < 0 || nextx >= m || nexty < 0 || nexty >= n) continue;
        if (grid[nextx][nexty] == '1') {
            grid[nextx][nexty] = '0';
            recur(grid, nextx, nexty);
        }
    }
}
int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int res = 0;
    for (int i = 0; i < m; ++ i) {
        for (int j = 0; j < n; ++ j) {
            if (grid[i][j] == '1') {
                grid[i][j] = '0';
                ++ res;
                recur(grid, i, j);
            }
        }
    }
    return res;
}