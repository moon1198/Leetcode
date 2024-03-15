#include <bits/stdc++.h>

using namespace std;

int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
void recur1020_0(vector<vector<int>>& grid, int i, int j) {
    grid[i][j] = 0;
    for (int k = 0; k < 4; ++ k) {
        int nextx = i + dir[k][0];
        int nexty = j + dir[k][1];
        if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) {
            continue;
        }else {
            if (grid[nextx][nexty] == 1) {
                recur1020_0(grid, nextx, nexty);
            }
        }
    }

}

int numEnclaves(vector<vector<int>>& grid) {
    vector<vector<int>> grid_cp(grid.begin(), grid.end());
    for (int i = 0; i < grid_cp[0].size(); ++ i) {
        if (grid_cp[0][i] == 1) {
            recur1020_0(grid_cp, 0, i);
        }
        if (grid_cp[grid_cp.size() - 1][i] == 1) {
            recur1020_0(grid_cp, grid_cp.size() - 1, i);
        }
    }
    for (int i = 1; i < grid_cp.size() - 1; ++ i) {
        if (grid_cp[i][0] == 1) {
            recur1020_0(grid_cp, i, 0);
        }
        if (grid_cp[i][grid_cp[0].size() - 1] == 1) {
            recur1020_0(grid_cp, i, grid_cp[0].size() - 1);
        }
    }
    int ans = 0;
    for (int i = 0; i < grid_cp.size(); ++ i) {
        for (int j = 0; j < grid_cp[0].size(); ++ j) {
            if (grid_cp[i][j] == 1) {
                ++ ans;
            }
        }
    }
    return ans;
}