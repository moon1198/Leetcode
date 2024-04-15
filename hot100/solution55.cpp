#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {
    //不包含
    int r_idx = nums[0] + 1;
    for (int i = 0; i < r_idx && i < nums.size(); ++ i) {
        r_idx = max(r_idx, i + nums[i] + 1);
    }
    if  (r_idx >= nums.size()) {
        return true;
    }
    return false;
}