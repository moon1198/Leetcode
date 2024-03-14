#include <bits/stdc++.h>

using namespace std;

//int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
//
//void recur695_0(vector<vector<int>>& grid, int i, int j, int &area) {
//    grid[i][j] == 0;
//    area ++;
//    for (int k = 0; k < 4; ++ k) {
//        int nextx = i + dir[k][0];
//        int nexty = j + dir[k][1];
//        if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) {
//            continue;
//        }else {
//            if (grid[nextx][nexty] == 1) {
//                recur695_0(grid, nextx, nexty, area);
//            }
//        }
//    }
//}
//
//int maxAreaOfIsland(vector<vector<int>>& grid) {
//    vector<vector<int>> grid_cp(grid.begin(), grid.end());
//    int ans = 0;
//    for (int i = 0; i < grid.size(); ++ i) {
//        for (int j = 0; j < grid[0].size(); ++ j) {
//            if (grid[i][j] == 1) {
//                int area = 0;
//                recur695_0(grid_cp, i, j, area);
//                ans = max(ans, area);
//            }
//        }
//    }
//    return ans;
//}

void recur695_0(vector<vector<int>>& grid, int i, int j, int &area) {
    grid[i][j] = 0;
    //up
    if (i > 0 && grid[i - 1][j] == 1) {
        ++ area;
        recur695_0(grid, i - 1, j, area);
    }
    //down
    if (i < grid.size() - 1 && grid[i + 1][j] == 1) {
        ++ area;
        recur695_0(grid, i + 1, j, area);
    }
    //left
    if (j > 0 && grid[i][j - 1] == 1) {
        ++ area;
        recur695_0(grid, i, j - 1, area);
    }
    //right
    if (j < grid[0].size() - 1 && grid[i][j + 1] == 1) {
        ++ area;
        recur695_0(grid, i, j + 1, area);
    }
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    vector<vector<int>> grid_cp(grid.begin(), grid.end());
    int ans = 0;
    for (int i = 0; i < grid.size(); ++ i) {
        for (int j = 0; j < grid[0].size(); ++ j) {
            if (grid[i][j] == 1) {
                int area = 1;
                recur695_0(grid, i, j, area);
                ans = max(ans, area);
            }
        }
    }
    return ans;
}