#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n) {
    //扩容，避免越界
    vector<int> dp(n + 2, 1);
    dp[1] = 1; dp[2] = 2;
    for (int i = 2; i < n + 1; ++ i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}