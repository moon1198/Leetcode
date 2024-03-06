#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std; 

int solution647_0(string s) {
    int res = 0;
    vector<vector<bool>>dp(s.size(), vector<bool>(s.size(), false));

    //从下向上， 从左往右
    // for (int i = s.size() - 1; i >= 0; -- i) {
    //     for (int j = i; j < s.size(); ++ j) {
    //         if (s[i] == s[j]) {
    //             if (i == j) {
    //                 dp[i][j] = true;
    //             } else if (j - i == 1) {
    //                 dp[i][j] = true;
    //             } else {
    //                 dp[i][j] = dp[i + 1][j - 1];
    //             }
    //         } else {
    //             dp[i][j] = false;
    //         }
    //     }
    // }

    //或者先纵向遍历

    //斜向遍历
    for (int j = 0; j < s.size(); ++ j) {
        int k = j;
        for (int i = 0; i < s.size() - j; ++ j, ++ k) {
            if (s[i] == s[k]) {
                if (i == k) {
                    dp[i][k] = true;
                } else if (k - i == 1) {
                    dp[i][k] = true;
                } else {
                    dp[i][k] = dp[i + 1][k - 1];
                }
            } else {
                dp[i][k] = false;
            }

        }
    }
    for (int i = 0; i < s.size(); ++ i) {
        for (int j = i; j < s.size(); ++ j) {
            if (dp[i][j])
            ++ res;
        }
    }
    return res;
}