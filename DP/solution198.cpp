#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int solution198_0(vector<int>& nums) {
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    if (nums.size() > 1) {
        dp[1] = max(nums[0], nums[1]);
    }

    for (int i = 2; i < nums.size(); ++ i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    return dp.back();
}