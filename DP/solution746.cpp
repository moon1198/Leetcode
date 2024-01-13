#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int solution746_0(vector<int> &cost) {
    if (cost.size() < 3) return 0;
    vector<int> dp(cost.size() + 1, 0);
    for (int i = 2; i < dp.size(); ++ i) {
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    return dp.back();
}