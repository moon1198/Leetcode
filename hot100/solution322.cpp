#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
    for (int coin = 0; coin < n + 1; ++ coin) {
        dp[coin][0] = 0;
    }
    //for (int coin = 1; coin < n + 1; ++ coin) {
    //    for (int sum = 1; sum < amount + 1; ++ sum) {
    //        int tmp = INT_MAX;
    //        if (dp[coin - 1][sum] != -1) {
    //            tmp = dp[coin - 1][sum];
    //        }
    //        for (int i = 0; i < coin; ++ i) {
    //            if (sum - coins[i] >= 0 && dp[coin][sum - coins[i]] != -1) {
    //                tmp = min(tmp, dp[coin][sum - coins[i]] + 1);
    //            }
    //        }
    //        if (tmp == INT_MAX) {
    //            tmp = -1;
    //        }
    //        dp[coin][sum] = tmp;
    //    }
    //}

    for (int coin = 1; coin < n + 1; ++ coin) {
        for (int sum = 1; sum < amount + 1; ++ sum) {
            int tmp = INT_MAX;
            if (dp[coin - 1][sum] != -1) {
                tmp = dp[coin - 1][sum];
            }
            if (sum - coins[coin - 1] >= 0 && dp[coin][sum - coins[coin - 1]] != -1) {
                tmp = min(tmp, dp[coin][sum - coins[coin - 1]] + 1);
            }
            if (tmp == INT_MAX) {
                tmp = -1;
            }
            dp[coin][sum] = tmp;
        }
    }
    
    return dp[n][amount];
}