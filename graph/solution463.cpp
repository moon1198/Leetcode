#include <bits/stdc++.h>

using namespace std;

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

void dfs(vector<vector<int>> &grid, int i, int j, int &count) {
    grid[i][j] = 0;

    int m = grid.size();
    int n = grid[0].size();
    for (int k = 0; k < 4; ++ k) {
        int nextx = i + dir[k][0];
        int nexty = j + dir[k][1];
        if (nextx >= m || nextx < 0 || nexty < 0 || nexty >= n) continue;
        if (grid[nextx][nexty] == 1) {
            ++ count;
            dfs(grid, nextx, nexty, count);
        }
    }

}

int islandPerimeter(vector<vector<int>>& grid) {
    vector<vector<int>> grid_cp(grid.begin(), grid.end());
    int m = grid.size();
    int n = grid[0].size();

    int count = 0;
    int repeat_count = 0;
    for (int i = 0; i < m; ++ i) {
        for (int j = 0; j < n; ++ j) {
            if (grid[i][j] == 1) {
                for (int k = 0; k < 4; ++ k) {
                    int nextx = i + dir[k][0];
                    int nexty = j + dir[k][1];
                    if (nextx >= m || nextx < 0 || nexty < 0 || nexty >= n) continue;
                    if (grid[nextx][nexty] == 1) {
                        ++ repeat_count;
                    }
                }
            }
        }
    }

    for (int i = 0; i < m; ++ i) {
        for (int j = 0; j < n; ++ j) {
            if (grid_cp[i][j] == 1) {
                count = 1;
                dfs(grid_cp, i, j, count);
                return count * 4 - repeat_count;
            }
        }
    }
    return 0;
}


int islandPerimeter1(vector<vector<int>>& grid) {
    
    int m = grid.size();
    int n = grid[0].size();

    int count = 0;

    for (int i = 0; i < m; ++ i) {
        for (int j = 0; j < n; ++ j) {
            if (grid[i][j] == 1) {
                for (int k = 0; k < 4; ++ k) {
                    int nextx = i + dir[k][0];
                    int nexty = j + dir[k][1];
                    if (nextx >= m || nextx < 0 || nexty < 0 || nexty >= n) {
                        ++ count;
                        continue;
                    }
                    if (grid[nextx][nexty] == 0) {
                        ++ count;
                    }
                }
            }
        }
    }
    return count;
}