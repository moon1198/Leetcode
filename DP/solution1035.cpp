#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std; 

int solution1135_0(vector<int>& nums1, vector<int>& nums2) {
    //最长公共子序列
    //当前状态下的解
    vector<vector<int>>dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
    for (int i = 1; i < nums1.size() + 1; ++ i) {
        for (int j = 1; j < nums2.size() + 1; ++ j) {
            if (nums1[i - 1] == nums2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp.back().back();
}