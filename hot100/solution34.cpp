#include <bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    int m;
    while (l <= r) {
        m = l + ((r - l) >> 1);
        if (nums[m] == target) {
            break;
        } else if (nums[m] > target) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    if (l > r) {
        return {-1, -1};
    }
    vector<int> ans(2, m);
    while (ans[0] - 1 >= 0 && nums[ans[0] - 1] == nums[ans[0]]) {
        -- ans[0];
    }
    while (ans[1] + 1 < nums.size() && nums[ans[1] + 1] == nums[ans[1]]) {
        ++ ans[1];
    }
    return ans;
}