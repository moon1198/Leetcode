#include <bits/stdc++.h>
using namespace std;

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

int orangesRotting0(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    bool flag = true;
    int ans = -1;
    while (flag) {
        flag = false;
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (grid[i][j] == 2) {
                    for (int k = 0; k < 4; ++ k) {
                        int nextx = i + dir[k][0];
                        int nexty = j + dir[k][1];
                        if (nextx < 0 || nextx >= m || nexty < 0 || nexty >= n) continue;
                        if (grid[nextx][nexty] == 1) {
                            flag = true;
                            grid[nextx][nexty] = 3;
                        }
                    }
                }

            }
        }
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (grid[i][j] == 3) {
                    grid[i][j] = 2;
                }
            }
        }
        ans ++;
    }
    for (int i = 0; i < m; ++ i) {
        for (int j = 0; j < n; ++ j) {
            if (grid[i][j] == 1) {
                return -1;
            }
        }
    }
    return ans;
}

int orangesRotting(vector<vector<int>>& grid) {
    int dis[10][10];
    memset(dis, -1, sizeof(dis));
    int cnt = 0;
    queue<vector<int>>que;

    int m = grid.size(); int n = grid[0].size();
    int ans = 0;
    for (int i = 0; i < m; ++ i) {
        for (int j = 0; j < n; ++ j) {
            if (grid[i][j] == 2) {
                dis[i][j] = 0;
                que.push({i, j});
            } else if (grid[i][j] == 1) {
                ++ cnt;
            }
        }
    }
    while (!que.empty()) {
        vector<int>tmp = que.front();
        que.pop();
        for (int i = 0; i < 4; ++ i) {
            int x = tmp[0] + dir[i][0]; int y = tmp[1] + dir[i][1];
            if (x < 0 || x >= m || y < 0 || y >= n) continue;
            if (grid[x][y] == 1) {
                grid[x][y] = 2;
                que.push({x, y});
                dis[x][y] = dis[tmp[0]][tmp[1]] + 1;
                ans = dis[x][y];
                -- cnt;
                if (cnt == 0) return ans;
            }
        }
    }
    if (cnt == 0) return ans;
    return -1;
}