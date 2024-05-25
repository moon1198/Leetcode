#include <bits/stdc++.h>
using namespace std;

int minDistance(string word1, string word2) {
    //交换无意义，
    string long_str, short_str;
    if (word1.size() > word2.size()) {
        long_str = word1;
        short_str = word2;
    } else {
        long_str = word2;
        short_str = word1;
    }
    int m = long_str.size(), n = short_str.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i < n + 1; ++ i) {
        dp[0][i] = i;
    }
    for (int i = 1; i < m + 1; ++ i) {
        dp[i][0] = i;
    }
    for (int i = 0; i < m; ++ i) {
        for (int j = 0; j < n; ++ j) {
            if (long_str[i] == short_str[j]) {
                dp[i + 1][j + 1] = dp[i][j];
            } else {
                int tmp = min(dp[i][j + 1], dp[i][j]);
                tmp = min(tmp, dp[i + 1][j]);
                dp[i + 1][j + 1] = tmp + 1;
            }
        }
    }

    return dp.back().back();
}