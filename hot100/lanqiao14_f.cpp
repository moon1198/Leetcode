#include <bits/stdc++.h>
using namespace std;


int bar() {
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    int dp[n + 1][m + 1] = {};
    for (int i = 1; i < m + 1; ++ i) {
        if (i % 2 == 1) {
            dp[1][i] = 1;
        } else {
            dp[1][i] = 0;
        }
    }
    for (int i = 2; i < n + 1; ++ i) {
        for (int j = 1; j < m + 1; ++ j) {
            int tmp = 0;
            if (i % 2 == 0) {
                // if (i == n) {
                //     for (int k = 1; k < 5; ++ k) {
                //         if (j - k * 2 >= 0) {
                //             tmp += dp[i - 1][j - 2 * k];
                //         }
                //     }
                // } else {
                    for (int k = 0; k < 5; ++ k) {
                        if (j - k * 2 >= 0) {
                            tmp += dp[i - 1][j - 2 * k];
                        }
                    }
                // }
            } else {
                for (int k = 0; k < 5; ++ k) {
                    if (j - k * 2 - 1 >= 0) {
                        tmp += dp[i - 1][j - 2 * k - 1];
                    }
                }
            }
            dp[i][j] = tmp;
        }
    }
    int ans = 0; 
    if (n % 2 == 1) {
        ans = dp[m][n];
    } else {
        for (int k = 1; k < 5; ++ k) {
            if (m - k * 2 >= 0) {
                ans += dp[n - 1][m - 2 * k];
            }
        }
    }
    cout << ans % 998244353 << endl;

    return 0;
}