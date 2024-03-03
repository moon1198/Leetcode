#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int solution121_0(vector<int>& prices) {
    vector<int> dp(prices.size(), 0);
    int min_price = prices[0];
    dp[0] = 0;
    
    for (int i = 1; i < dp.size(); ++ i) {
        dp[i] = max(dp[i - 1], prices[i] - min_price);
        min_price = min(min_price, prices[i]);
    }
    return dp.back();
}

int solution121_1(vector<int>& prices) {
    vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
    dp[0][0] = -prices[0];
    dp[0][1] = 0;

    for (int i = 1; i < prices.size(); ++ i) {
        dp[i][0] = max(dp[i - 1][0], -prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }
    return dp.back()[1];
}