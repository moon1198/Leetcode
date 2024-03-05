#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int solution300_0(vector<int>& nums) {
    //统计i前有多少小于nums[i]的元素, 即以nums[i]为尾元素时
    vector<int>dp(nums.size(), 1);
    int res = 1;
    for (int i = 1; i < nums.size(); ++ i) {
        for (int j = 0; j < i; ++ j) {
            if(nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
    }
    return res;
    //return max_element(dp.begin(), dp.end());
}