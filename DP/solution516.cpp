#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std; 

int solution516_0(string s) {
    vector<vector<int>>dp(s.size(), vector<int>(s.size(), 0));
    for (int i = s.size() - 1; i >= 0; -- i) {
        for (int j = i; j < s.size(); ++ j) {
            if (s[i] == s[j]) {
                if (i == j) {
                    dp[i][j] = 1;
                } else if (j - i == 1) {
                    dp[i][j] = 2;
                } else {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[0][s.size() - 1];
}

int solution516_1(string s) {
    vector<vector<int>>dp(s.size(), vector<int>(s.size(), 0));
    for (int i = 0; i < s.size(); ++ i) dp[i][i] = 1;
    for (int i = s.size() - 1; i >= 0; -- i) {
        for (int j = i + 1; j < s.size(); ++ j) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[0][s.size() - 1];
}