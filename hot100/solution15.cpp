#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> ans;
    int left, right;
    for (int i = 0; i < n; ++ i) {
        if (nums[i] > 0) {
            break;
        }
        left = i + 1; right = n - 1;
        while (right > left) {
            if (nums[i] + nums[left] + nums[right] > 0) {
                -- right;
            } else if (nums[i] + nums[left] + nums[right] < 0) {
                ++ left;
            } else {
                ans.push_back({nums[i], nums[left], nums[right]});
                //seek the next pair begin of i
                while (right > left + 1 && nums[left] == nums[left + 1]) {
                    ++ left;
                }
                while (right - 1 > left && nums[right - 1] == nums[right]) {
                    -- right;
                }
                ++ left;
                -- right;
            }
        }
        //略去重复开头
        while (i + 1 < n && nums[i + 1] == nums[i]) {
            ++ i;
        }
    }
    return ans;
}