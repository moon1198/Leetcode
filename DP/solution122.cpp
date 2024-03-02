#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int solution122_0(vector<int>& prices) {
    vector<int>dp(prices.size(), 0);
    for (int i = 1; i < prices.size(); ++ i) {
        dp[i] = dp[i - 1] + max(prices[i] - prices[i - 1], 0);
    }
    return dp.back();
}