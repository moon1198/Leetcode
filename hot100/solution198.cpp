#include <bits/stdc++.h>
using namespace std;

int rob(vector<int>& nums) {
    //对于新的房屋， 偷或不偷；
    //两种状态转移
    int n = nums.size();
    if (n == 1) {
        return nums[0];
    }else if (n == 2) {
        return max(nums[0], nums[1]);
    }
    vector<int> dp(n + 1, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; ++ i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    return dp[n - 1];
}