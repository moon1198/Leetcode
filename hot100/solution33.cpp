#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {

    int base;
    if (nums.size() == 1) {
        base = 0;
    } else {
        //考虑有无反转，又为一反转区间为空
        for (base = 1; base < nums.size() && nums[base] > nums[base - 1]; ++ base) {
        }
    }

    int l = 0, r = nums.size();
    while (l < r) {
        int m = l + ((r - l) >> 1);
        //convert
        int real_m = (m + base) % nums.size();

        if (nums[real_m] == target) {
            return real_m;
        } else if (target < nums[real_m]) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    
    return -1;
}