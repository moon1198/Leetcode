#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std; 

int less_num (string str1) {
    vector<vector<bool>>dp(str1.size() + 1, vector<bool>(str1.size() + 1, false));
    int ans = 0;
    for (int i = dp.size() - 1; i >= 1; -- i) {
        for (int j = i + 1; j < dp.size(); ++ j) {
            if (str1[i - 1] > str1[j - 1]) {
                dp[i][j] = true;
                ++ ans;
            } else if ((str1[i - 1] == str1[j - 1]) && (j - i >= 2)) {
                if (dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    ++ ans;
                }
            }
        }
    }

    return ans;
}