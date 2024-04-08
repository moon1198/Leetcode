#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int l = 0, r = nums.size();
    int m;
    while (r > l) {
        m = (l + r) / 2;
        if (target == nums[m]) {
            return m;
        } else if (target > nums[m]) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    if (l == nums.size()) {
        return nums.size();
    }
    if (r == l) {
        if (target > nums[l]) {
            return l + 1;
        } else {
            return l;
        }
    }
    return -1;
}