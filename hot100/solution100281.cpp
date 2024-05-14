#include <bits/stdc++.h>
using namespace std;

int maxScore(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    //左上角最小值
    vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
    dp[0][0] = grid[0][0];
    int ans = INT_MIN;
    for (int i = 0; i < m; ++ i) {
        for (int j = 0 ; j < n; ++ j) {
            //cout << i << "; " << j << endl;
            if (i == 0 && j == 0) continue;
            int tmp = INT_MAX;
            if (i - 1 >= 0) {
                tmp = min(tmp, dp[i - 1][j]);
                tmp = min(tmp, grid[i - 1][j]);
            }
            if (j - 1 >= 0) {
                tmp = min(tmp, dp[i][j - 1]);
                tmp = min(tmp, grid[i][j - 1]);
            }
            dp[i][j] = tmp;
            ans = max(ans, grid[i][j] - dp[i][j]);
        }
    }
    return ans;
}