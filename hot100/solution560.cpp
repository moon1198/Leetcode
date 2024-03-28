#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k) {

//暴力
    int ans = 0;
    for (int start = 0; start < nums.size(); ++ start) {
        int sum = 0;
        for (int end = start; end >= 0; -- end) {
            sum += nums[end];
            if (sum == k) {
                ans ++;
            }
        }
    }
    return ans;
}

int subarraySum1(vector<int>& nums, int k) {
    //前缀和，记录求和过程
    //由前i + n的和， 减去前i的和得k
    int ans = 0;
    int pre_sum = 0;
    unordered_map<int, int>mp;
    mp[0] = 1;

    for (auto &num : nums) {
        pre_sum += num;
        if (mp.find(pre_sum - k) != mp.end()) {
            ans += mp[pre_sum - k];
        }
        mp[pre_sum] ++;
    }
    return ans;
}