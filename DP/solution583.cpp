#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std; 

int solution583_0(string word1, string word2) {
    //寻找最长公共子序列， 删去之外的，则获得相同字符
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
    for (int i = 1; i < word1.size() + 1; ++ i) {
        for (int j = 1; j < word2.size() + 1; ++ j) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return word1.size() + word2.size() - 2 * dp.back().back();
}
