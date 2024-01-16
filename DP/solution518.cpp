#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int solution518_0(int amount, vector<int> &coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < coins.size(); ++ i) {
        for (int j = 0; j < amount + 1; ++ j) {
            if (j >= coins[i]) {
                dp[j] += dp[j - coins[i]];
            }
        }
    }
    return dp.back();
}

int solution518_1(int amount, vector<int> &coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < coins.size(); ++ i) {
        for (int j = coins[i]; j < amount + 1; ++ j) {
            dp[j] += dp[j - coins[i]];
        }
        for (auto &num : dp) {
            cout << num << "; ";
        }
        cout << endl;
    }
    cout << endl;
    return dp.back();
}

//翻转后不行
int solution518_2(int amount, vector<int> &coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int j = 0; j <= amount; j++) { // 遍历背包容量
        for (int i = 0; i < coins.size(); i++) { // 遍历物品
            if (j - coins[i] >= 0) dp[j] += dp[j - coins[i]];
            cout << dp[j] << "; ";
        }
        cout << endl;
    }
    return dp.back();
}