#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int len = nums.size();
    vector<int> dp(len + 1, 1);
    dp[0] = 0;
    for (int i = 1; i < len + 1; ++ i) {
        for (int j = 0; j < i; ++ j) {
            int tmp = 1;
            if (nums[i - 1] > nums[j]) {
                tmp = dp[j + 1] + 1;
            }
            dp[i] = max(dp[i], tmp);
        }
    }
    int res = 0; 
    for (int i = 0; i < dp.size(); ++ i) {
        res = max(res, dp[i]);
    }
    return res;
}