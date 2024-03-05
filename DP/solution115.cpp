#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std; 

int solution115_0(string s, string t) {
    vector<vector<double>>dp(s.size() + 1, vector<double>(t.size() + 1, 0));
    for (int i = 0; i < s.size() + 1; ++ i)
    dp[i][0] = 1;
    for (int i = 1; i < s.size() + 1; ++ i) {
        for (int j = 1; j < t.size() + 1; ++ j) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    // for (auto it : dp) {
    //     for (auto num : it) {
    //         cout << num << "; ";
    //     }
    //     cout << endl;
    // }
    return static_cast<int>(dp.back().back()) % static_cast<int>(pow(10, 9) + 7);
}