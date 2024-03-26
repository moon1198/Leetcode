#include <bits/stdc++.h>
using namespace std;

int longestConsecutive0(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int>mp;
    int ans = 0;
    for (int i = 0; i < n; ++ i) {
        if (!mp[nums[i]]) {
            //not found
            int l = mp[nums[i] - 1];
            int r = mp[nums[i] + 1];
            int tmp = l + r + 1;
            mp[nums[i]] = tmp;
            mp[nums[i] - l] = tmp;
            mp[nums[i] + r] = tmp;
            ans = max(ans, tmp);
        }
    }
    return ans;
}

int longestConsecutive1(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
        return 0;
    }
    sort(nums.begin(), nums.end());
    int ans = 1;
    int mx = 1;
    for (int i = 1; i < n; ++ i) {
        if (nums[i] == nums[i - 1] + 1) {
            ++ mx;
            ans = max(ans, mx);
        } else if (nums[i] == nums[i - 1]) {
        } else {
            mx = 1;
        }
    }
    return ans;
}
