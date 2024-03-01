#include <vector>
#include <string>
#include <map>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

bool solution139_0(string s, vector<string>& wordDict) {
    vector<bool>dp(s.size() + 1, false);
    dp[0] = true;
    unordered_set<string>words(wordDict.begin(), wordDict.end());
    //i表示字符长度
    for (int i = 1; i < dp.size(); ++ i) {
        //j表示字符索引
        for (int j = 0; j < i; ++ j) {
            string word = s.substr(j, i - j);
            if (words.find(word) != words.end() && dp[j]) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp.back();
}