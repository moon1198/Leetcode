#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std; 

int solution72_0(string word1, string word2) {
    vector<vector<int>>dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
    for (int i = 1; i < word1.size() + 1; ++ i) {
        dp[i][0] = i;
    }
    for (int i = 1; i < word2.size() + 1; ++ i) {
        dp[0][i] = i;
    }
    for (int i = 1; i < word1.size() + 1; ++ i) {
        for (int j = 1; j < word2.size() + 1; ++ j) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i -1][j - 1];
            } else {
                //增， 删， 改
                dp[i][j] = min({dp[i][j - 1] + 1, dp[i - 1][j] + 1, dp[i - 1][j - 1] + 1});
            }
        }
    }
    for (auto it : dp) {
        for (auto num : it) {
            cout << num << "; ";
        }
        cout << endl;
    }
    return dp.back().back();
}