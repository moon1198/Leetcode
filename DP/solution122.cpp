#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

//对于每天的股市行情， 都有着几种状态选择， 记录每一种状态下的最大值
int solution122_0(vector<int>& prices) {
    vector<int>dp(prices.size(), 0);
    for (int i = 1; i < prices.size(); ++ i) {
        dp[i] = dp[i - 1] + max(prices[i] - prices[i - 1], 0);
    }
    return dp.back();
}

int solution122_0(vector<int>& prices) {
    vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
    //0:持有状态， 1：非持有状态

    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    for (int i = 1; i < prices.size(); ++ i) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }
    return dp.back()[1];
}