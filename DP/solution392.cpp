#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std; 

bool solution392_0(string s, string t) {
    if (s.size() == 0) {
        return true;
    }
    vector<vector<int>>dp(t.size() + 1, vector<int>(s.size() + 1, 0));
    for (int i = 1; i < t.size() + 1; ++ i) {
        for (int j = 1; j < s.size() + 1; ++ j) {
            if (s[j - 1] == t[i - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i -1][j], dp[i][j - 1]);
            }
            if (dp[i][j] == s.size())
            return true;
        }
    }
    return false;
}


bool solution392_1(string s, string t) {
    if (s.size() == 0) {
        return true;
    }
    int j = 0;
    for (int i = 0; i < s.size(); ++ i) {
        for (; j < t.size(); ++ j) {
            if (s[i] == t[j]) {
                if (i == s.size() - 1)
                return true;
                ++ j;
                break;
            }
        }
    }
    return false;
}