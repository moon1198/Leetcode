#include <bits/stdc++.h>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    int len = s.size();
    int wnum = wordDict.size();
    vector<vector<bool>> dp(wnum + 1, vector<bool>(len + 1, false));
    for (int i = 0; i < wnum + 1; ++ i) {
        dp[i][0] = true;
    }
    for (int j = 1; j < len + 1; ++ j) {
        for (int i = 1; i < wnum + 1; ++ i) {
            int flag = false;
            int ltmp = wordDict[i - 1].size();
            if (j - ltmp >= 0 && dp[wnum][j - ltmp]) {
                flag = true;
                int bgn = j - ltmp;
                string stmp = s.substr(bgn, ltmp);
                if (stmp != wordDict[i -1]) {
                    flag = false;
                }

                //int bgn = j - ltmp;
                //for (int k = 0; k < ltmp; ++ k) {
                //    if (wordDict[i - 1][k] != s[bgn + k]) {
                //        flag = false;
                //        break;
                //    }
                //}
            }
            dp[i][j] = dp[i - 1][j] || flag;
        }
    }
    return dp.back().back();
}