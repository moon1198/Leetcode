#include <bits/stdc++.h>
using namespace std;

int min_prev(vector<vector<int>>& dp, int i, int j) {
    int m = dp.size(), n = dp[0].size();
    if (i - 1 < 0 && j - 1 < 0) {
        return 0;
    } else if (i - 1 >= 0 && j - 1 >= 0) {
        return min(dp[i - 1][j], dp[i][j - 1]);
    } else if (i - 1 >= 0) {
        return dp[i - 1][j];
    } else if (j - 1 >= 0) {
        return dp[i][j - 1];
    }
    return 0;
}

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++ i) {
        for (int j = 0; j < n; ++ j) {
            dp[i][j] = min_prev(dp, i, j) + grid[i][j];
        }
    }
    return dp.back().back();
}