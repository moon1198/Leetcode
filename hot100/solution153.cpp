#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums) {
    //寻找原首元素位置，
    int l = 0, r = nums.size() - 1; 
    while (l < r) {
        //终止后应使l==r;避免出现l>r case
        int m = l + ((r - l) >> 1);
        if (nums[0] > nums[m]) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    int idx;
    if (nums[l] > nums[0]) idx = l + 1;
    else idx = l;
    idx %= nums.size();

    return nums[idx];
}