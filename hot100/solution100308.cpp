#include <bits/stdc++.h>
using namespace std;

vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
    vector<int> dp(n, 0);
    int prev = 0;
    int flag = nums[0] % 2;
    for (int i = 1; i < n; ++ i) {
        int tmp = nums[i] % 2;
        if (tmp == flag) {
            prev = i;
        }
        dp[i] = prev;
        flag = tmp; 
    }
    vector<bool> ans;
    for (auto &it : queries) {
        if (dp[it[1]] <= it[0]) {
            ans.push_back(true);
        } else {
            ans.push_back(false);
        }
    }
    return ans;
}