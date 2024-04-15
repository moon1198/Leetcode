#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int ans = 0;
    int less = prices[0];
    for (int i = 1; i < prices.size(); ++ i) {
        ans = max(ans, prices[i] - less);
        less = min(less, prices[i]);
    }
    return ans;
}