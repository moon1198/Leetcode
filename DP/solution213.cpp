#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;


int robRange(vector<int>& nums, int begin, int end) {
    //len < 0
    if (begin >= end) {
        return 0;
    }
    //len == 1
    if (end - begin == 1) return nums[begin];
    //len >= 2
    vector<int>dp(end, 0);

    dp[begin] = nums[begin];
    dp[begin + 1] = max(nums[begin + 1], nums[begin]);
    for (int i = begin + 2; i < end; ++ i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    // cout << begin << " "<< end << " " << dp.back() << endl;
    return dp.back();
}

int solution213_0(vector<int>& nums) {
    //左闭右开区间
    return max(robRange(nums, 0, nums.size() - 1), robRange(nums, 1, nums.size()));
}

