#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
    vector<int> cnt(3, 0);
    for (int &num : nums) {
        cnt[num] ++;
    }
    for (int i = 0; i < cnt[0]; ++ i) {
        nums[i] = 0;
    } 
    for (int i = cnt[0]; i < cnt[1] + cnt[0]; ++ i) {
        nums[i] = 1;
    } 
    for (int i = cnt[0] + cnt[1]; i < cnt[0] + cnt[1] + cnt[2]; ++ i) {
        nums[i] = 2;
    } 
}

void sortColors(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    int i = 0;
    while (i <= r) {
        if (nums[i] == 0) {
            swap(nums[i], nums[l]);
            ++ l; ++ i;
        } else if (nums[i] == 1) {
            ++ i;
        } else if (nums[i] == 2) {
            swap(nums[i], nums[r]);
            -- r;
        }
    }
}