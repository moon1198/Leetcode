#include <bits/stdc++.h>

using namespace std;

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
void island_size(vector<vector<int>>& grid_cp, vector<vector<int>>& number, int i, int j, int &count, int num) {
    ++ count;
    grid_cp[i][j] = 0;
    number[i][j] = num;

    int n = grid_cp.size();
    for (int k = 0; k < 4; ++ k) {
        int nextx = i + dir[k][0];
        int nexty = j + dir[k][1];
        if (nextx >= n || nextx < 0 || nexty < 0 || nexty >= n) continue;
        if (grid_cp[nextx][nexty] == 1) {
            island_size(grid_cp, number, nextx, nexty, count, num);
        }
    }
}

//num : count
map<int, int>mp;

int largestIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> grid_cp(grid.begin(), grid.end());
    vector<vector<int>>number(n, vector<int>(n, 0));

    //the number of island
    int num = 1;
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            int count = 0;
            if (grid_cp[i][j] == 1) {
                island_size(grid_cp, number, i, j, count, num);
                mp[num] = count;
                ++ num;
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            if (grid[i][j] == 0) {
                int tmp = 1;
                set<int> flags;

                for (int k = 0; k < 4; ++ k) {
                    int nextx = i + dir[k][0];
                    int nexty = j + dir[k][1];
                    if (nextx >= n || nextx < 0 || nexty < 0 || nexty >= n) continue;
                    flags.insert(number[nextx][nexty]);
                }
                for (auto it : flags) {
                    tmp += mp[it];
                    res = max(res, tmp);
                }
            }
        }
    }
    if (res == 0) {
        res = n * n;
   }

    return res;
}