#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int solution474_0(vector<string> &strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int k = 0; k < strs.size(); ++ k) {
        int oneNum = 0, zeroNum = 0;
        for (char c : strs[k]) {
            if (c == '0') {
                ++ zeroNum;
            } else {
                ++ oneNum;
            }
        }
        for (int i = m; i >= zeroNum; -- i) {
            for (int j = n; j >= oneNum; -- j) {
                dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
            }
        }
    }
    return dp[m][n];
}