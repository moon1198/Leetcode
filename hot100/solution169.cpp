#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < nums.size(); ++ i) {
        if (cnt == 0) {
            ans = nums[i];
            cnt = 1;
            continue;
        }
        if (nums[i] == ans) {
            cnt ++;
        } else {
            cnt --;
        }
    }
    return ans;
}