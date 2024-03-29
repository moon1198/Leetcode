#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int solution123_0(vector<int>& prices) {
    //只适用于寻找两处，连续增的情况
    //dp[]      连续递增值  第一个买/售     第二个买/售
    vector<vector<int>>dp(prices.size(), vector<int>(3, 0));
    for (int i = 1; i < prices.size(); ++ i) {
        if (prices[i] - prices[i - 1] > 0) {
            dp[i][0] = dp[i - 1][0] + (prices[i] - prices[i - 1]);
            
            //在一个上升坡，只能替换由这个坡带来的收益
            if (dp[i - 1][0] == dp[i - 1][1]) {
                dp[i][1] = dp[i][0];
                dp[i][2] = dp[i - 1][2];
                continue;
            } else if (dp[i - 1][0] == dp[i - 1][2]) {
                dp[i][1] = dp[i - 1][1];
                dp[i][2] = dp[i][0];
                continue;
            }

            //替换更小者
            if (dp[i - 1][1] > dp[i - 1][2]) {
                dp[i][1] = dp[i - 1][1];
                dp[i][2] = max(dp[i - 1][2], dp[i][0]);
            }else {
                dp[i][1] = max(dp[i - 1][1], dp[i][0]);
                dp[i][2] = dp[i - 1][2];
            }
        } else {
            dp[i][0] = 0;
            dp[i][1] = dp[i - 1][1];
            dp[i][2] = dp[i - 1][2];
        }
    }
    return dp.back()[1] + dp.back()[2];
}

int solution123_1(vector<int>& prices) {
    //0:第一次持有； 1：第一次不持有；2：第二次持有； 3：第二次不持有
    vector<vector<int>>dp(prices.size(), vector<int>(4, 0));
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    dp[0][2] = -prices[0];
    dp[0][3] = 0;

    for (int i = 1; i < prices.size(); i ++) {
        dp[i][0] = max(dp[i - 1][0], -prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] - prices[i]);
        dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] + prices[i]);
    }
    return dp.back()[3];
}