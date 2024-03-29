#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf1(vector<int>& nums) {
    int n = nums.size();
    vector<int> pre(n, 0);
    vector<int> suf(n, 0);
    vector<int> ans(n, 0);
    pre[0] = 1;
    suf[n - 1] = 1;

    for (int i = 1; i < n; ++ i) {
        pre[i] = pre[i - 1] * nums[i - 1];
    }
    for (int i = n - 2; i >= 0; -- i) {
        suf[i] = suf[i + 1] * nums[i + 1];
    }
    for (int i = 0; i < n; ++ i) {
        ans[i] = pre[i] * suf[i];
    }
    return ans;
}

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 0);
    int tmp = 1;


    for (int i = 0; i < n; ++ i) {
        ans[i] = tmp;
        tmp *= nums[i];
    }
    tmp = 1;
    for (int i = n - 1; i >= 0; -- i) {
        ans[i] = ans[i] * tmp;
        tmp *= nums[i];
    }

    return ans;
}