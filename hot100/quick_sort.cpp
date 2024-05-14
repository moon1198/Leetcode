#include <bits/stdc++.h>
using namespace std;


void recur(vector<int>& nums, int l, int r) {
    if (l > r) {
        return ;
    }
    int tmp = nums[l];
    int t1 = l, t2 = r;
    bool flag = false;
    while (t1 != t2) {
        if (!flag) {
            if (nums[t2] > tmp) {
                -- t2;
            } else {
                nums[t1] = nums[t2];
                ++ t1;
                flag = true;
            }
        } else {
            if (nums[t1] < tmp) {
                ++ t1;
            } else {
                nums[t2] = nums[t1];
                -- t2;
                flag = false;
            }
        }
    }
    nums[t1] = tmp;
    recur(nums, l, t1 - 1);
    recur(nums, t1 + 1, r);
}

vector<int> quick_sort(vector<int>& nums) {
    int n = nums.size();
    recur(nums, 0, n - 1);
    return nums;
}