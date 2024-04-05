#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> ans;
vector<string> tmp;

// bool check(string s, int i, int j) {
//     while (i <= j) {
//         if (s[i] != s[j]) return false;
//         ++ i; -- j;
//     }
//     return true;
// }

// void backtrack(string s, int idx) {
//     if (idx >= s.size()) {
//         ans.push_back(tmp);
//         return;
//     }
//     for (int i = idx; i < s.size(); ++ i) {
//         if (!check(s, idx, i)) continue;
//         tmp.emplace_back(s.begin() + idx, s.begin() + i + 1);
//         backtrack(s, i + 1);
//         tmp.pop_back();
//     }
// }

// vector<vector<string>> partition(string s) {
//     int len = s.size();
//     backtrack(s, 0);
//     return ans;

// }

void backtrack(string s, vector<vector<bool>> &dp, int i) {
    if (i >= s.size()) {
        ans.push_back(tmp);
        return;
    }
    for (int j = i; j < s.size(); ++ j) {
        if (dp[i][j]) {
            tmp.emplace_back(s.begin() + i, s.begin() + j + 1);
            backtrack(s, dp, j + 1);
            tmp.pop_back();
        }
    }
}
//dp + backtrack
vector<vector<string>> partition(string s) {
    int len = s.size();
    vector<vector<bool>> dp(len, vector<bool>(len, false));
    for (int i = 0; i < len; ++ i) {
        for (int j = 0; j <= i; ++ j) {
            dp[i][j] = true;
        }
    }
    for (int i = len - 1; i >= 0; --i) {
        for (int j = i + 1; j < len; ++ j) {
            dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
        }
    }
    backtrack(s, dp, 0);
    return ans;

}
