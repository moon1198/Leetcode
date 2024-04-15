#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353

int bar() {
    int n = 9, m = 15;
    vector<int> Ai = {3, 2, 5, 7, 1, 4, 6, 8, 3};
    vector<uint64_t> dp(m, 0);
    for (int i = 0; i < dp.size(); ++ i) {
        dp[i] = Ai[0] * (m - i);
    }

    for (int i = 1; i < n; ++ i) {
        for (int j = 0; j < dp.size(); ++ j) {
            if (j == 0) {
                for (int k = 1; k < dp.size(); ++ k) {
                    dp[j] += (dp[k] * ((k - j) * Ai[i])) % MOD;
                    dp[j] %= MOD;
                }
            } else {
                int tmp = 0;
                for (int k = j + 1; k < dp.size(); ++ k) {
                    tmp += dp[k] * ((k - j) * Ai[i]);
                }
                dp[j] = tmp;
                dp[j] %= MOD;
            }
        }
    }
    int ret = 0;
    for (int i = 0; i < dp.size(); ++ i) {
        ret += dp[i];
        ret %= MOD;
    }
    cout << ret << endl;
    return ret;
}