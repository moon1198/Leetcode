#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool> (n, false));
    for (int i = 0; i < n; ++ i) {
        dp[i][i] = true;
    }
    int begin = 0, end = 0;
    for (int i = n - 1; i >= 0; -- i) {
        for (int j = i + 1; j < n; ++ j) {
            if (j - i == 1 && s[i] == s[j]) {
                dp[i][j] = true;
                if (j - i > end - begin) {
                    begin = i; end = j;
                }
                continue;
            } else {
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    if (j - i > end - begin) {
                        begin = i; end = j;
                    }
                }
            }
        }
    }
    string ans = s.substr(begin, end - begin + 1);
    
    return ans;
}