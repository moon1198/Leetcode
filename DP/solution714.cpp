#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int solution714_0(vector<int>& prices, int fee) {
    //0:持有 1：不持有
    vector<vector<int>>dp(prices.size(), vector<int>(2, 0));
    dp[0][0] = -prices[0] - fee;
    dp[0][1] = 0;
    for (int i = 1; i < prices.size(); ++ i) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i] - fee);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }
    return dp.back().back();
}