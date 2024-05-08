#include <bits/stdc++.h>
using namespace std;

bool canPartition0(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for (int &num : nums) {
        sum += num;
    }
    if (sum % 2 == 1) {
        return false;
    }
    int tar = sum / 2;
    //01背包问题，如何获得和tar
    vector<vector<bool>> dp(n, vector<bool> (tar + 1, false));
    for (int i = 0; i < n; ++ i) {
        dp[i][0] = true;
    }
    if (nums[0] <= tar) {
        dp[0][nums[0]] = true;
    }

    for (int i = 1; i < n; ++ i) {
        for (int j = 1; j < tar + 1; ++ j) {
            if (j - nums[i] >= 0) {
                dp[i][j] = dp[i - 1][j - nums[i]];
            }
            dp[i][j] = dp[i - 1][j] || dp[i][j];
        }
    }

    return dp.back().back();
}

bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum & 1) {
        return false;
    }
    int tar = sum >> 1;
    bitset<10001>bits(1);
    for (int i = 0; i < nums.size(); ++ i) {
        bits |= bits << nums[i];
    }
    return bits[tar];
}