#include <bits/stdc++.h>
using namespace std;

//暴力bfs， defeat
bool check(vector<int>& dict) {
    int flag = 0;
    for (int i = 0; i < dict.size(); ++ i) {
        if (dict[i] == 0) continue;
        if (dict[i] != 0 && flag == 0) {
            flag = dict[i];
        } else if (flag != 0 && flag != dict[i]){
            return false;
        }
    }
    return true;
}

int ans = INT_MAX;
void bfs (vector<vector<bool>>& dp, int i, int j, int len) {
    int n = dp.size();
    if (dp[i][j] == false) {
        return ;
    }
    if (len >= ans) return ;
    if (j + 1 >= n) {
        if (len < ans) {
            ans = len;
        }
        return ;
    }
    for (int k = j + 1; k < n; ++ k) {
        bfs(dp, j + 1, k, len + 1);
    }
}

int minimumSubstringsInPartition(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++ i) {
        vector<int> dict(26, 0);
        for (int j = i; j < n; ++ j) {
            ++ dict[s[j] - 'a'];
            if (check(dict)) {
                dp[i][j] = true;
            }
        }
    }

    int len = 1;
    for (int i = 0; i < n; ++ i) {
        bfs(dp, 0, i, len);
        //cout << ans << endl;
    }
    return ans;
}