#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int solution309_0(vector<int>& prices) {
    //0:持有， 1：非持有， 2：冷静期
    vector<vector<int>>dp(prices.size(), vector<int>(3, 0));
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    dp[0][2] = 0;
    for (int i = 1; i < prices.size(); ++ i) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][2] = dp[i - 1][0] + prices[i];
    }
    return dp.back().back();
}