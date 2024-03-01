#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int solution322_0(vector<int>& coins, int amount) {
    if (amount == 0) {
        return 0;
    }
    vector<int> dp(amount + 1, 0);
    dp[0] = 0;
    for (int i = 1; i < dp.size(); ++ i) {
        int tmp = INT_MAX;
        for (int j = 0; j < coins.size(); ++ j) {
            if (coins[j] <= i && (i - coins[j] == 0 || dp[i - coins[j]] > 0)) {
                tmp = min(tmp, dp[i - coins[j]] + 1);
                //dp[i] = dp[i] <= dp[i - coins[j]] + 1 ? dp[i] : dp[i - coins[j]] + 1;
            }
        }
        if (tmp != INT_MAX) {
            dp[i] = tmp;
        }
    }
    if (dp.back() == 0) {
        return -1;
    }
    return dp.back();
}

int solution322_1(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < dp.size(); ++ i) {
        for (int j = 0; j < coins.size(); ++ j) {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    if (dp.back() == INT_MAX) 
    return -1;
    return dp.back();
}
//dp[i] = min(dp[i - coins[j]] + 1);