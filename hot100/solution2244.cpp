#include <bits/stdc++.h>
using namespace std;

int minimumRounds(vector<int>& tasks) {
    unordered_map<int, int> mp;
    int cnt = 0; 
    for (auto &num : tasks) {
        mp[num] ++;
        cnt = max(cnt, mp[num]);
    }
    vector<int> dp(cnt + 4, INT_MAX);
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 4; i < dp.size(); ++ i) {
        int tmp = min(dp[i - 2], dp[i - 3]);
        if (tmp != INT_MAX) {
            dp[i] = tmp + 1;
        }
    }
    int ans = 0;
    for (auto &it : mp) {
        if (dp[it.second] == INT_MAX) {
            return -1;
        } else {
            ans += dp[it.second];
        }
    }
    return ans;
}

int minimumRounds(vector<int>& tasks) {
    //2, 3可组成除1以外所有数
    unordered_map<int, int> mp;
    for (auto &num : tasks) {
        mp[num] ++;
    }
    int ans = 0;
    for (auto &it : mp) {
        if (it.second == 1) {
            return -1;
        } else {
            ans += (it.second + 2) / 3;
        }
    }
    return ans;
}