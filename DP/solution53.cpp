#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std; 

int solution53_0(vector<int>& nums) {
    int res = nums[0];
    vector<int>dp(nums.size(), 0);
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); ++ i) {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        res = max(res, dp[i]);
    }
    return res;
}