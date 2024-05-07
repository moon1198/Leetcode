#include <bits/stdc++.h>
using namespace std;

vector<int> dict = {1, 0, -1};
//i:row, j:first idx, k:second idx
int backtrack(vector<vector<int>>& grid, int i, int j, int k, vector<vector<vector<int>>> &memo) {
    //timeout 
    int m = grid.size(), n = grid[0].size();
    int ans = 0;
    if (i >= m || j >= n || k >= n || j < 0 || k < 0) {
        return 0;
    }
    if (memo[i][j][k] != -1) {
        return memo[i][j][k];
    }
    int tmp = 0;
    for (int offset0 : dict) {
        for (int offset1 : dict) {
            tmp = max(tmp, backtrack(grid, i + 1, j + offset0, k + offset1, memo));
        }
    }
    if (j == k) {
        ans = tmp + grid[i][j];
    } else {
        ans = tmp + grid[i][j] + grid[i][k];
    }
    memo[i][j][k] = ans;
    return ans;
}

int cherryPickup(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    //记忆化，缩短时间
    vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(n, -1)));
    return backtrack(grid, 0, 0, n - 1, memo);
}