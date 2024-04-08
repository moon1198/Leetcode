#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

typedef struct{
    int dp[5][5][5][5];
}dp_t;
dp_t dp_cur = {0};

int bar() {
    //以最高位为首位
    int n ,m;
    cin >> n >> m;

    //init dp
    for (int a = 0; a < 5; ++ a) {
        for (int b = 0; b < 5; ++ b) {
            for (int c = 0; c < 5; ++ c) {
                for (int d = 0; d < 5; ++ d) {
                    int pre_val = 2 * (a + b + c + d) + 2;
                    if (pre_val <= m) {
                        dp_cur.dp[a][b][c][d] = 1;
                    } else {

                    }
                }
            }
        }
    }

    //
    for (int i = 5; i <= n; ++ i) {
        dp_t dp_tmp = {0};
        for (int a = 0; a < 5; ++ a) {
            for (int b = 0; b < 5; ++ b) {
                for (int c = 0; c < 5; ++ c) {
                    for (int d = 0; d < 5; ++ d) {
                        int pre_val = 2 * (a + b + c + d) + 2;
                        for (int j = 0; j < 5; ++ j) {
                            int cur_val = j * 2 + (i % 2);
                            if (pre_val + cur_val <= m) {
                                dp_tmp.dp[b][c][d][j] += dp_cur.dp[a][b][c][d];
                            }
                        }
                    }
                }
            }
        }
        dp_cur = dp_tmp;
    }
    int sum = 0;
    for (int a = 0; a < 5; ++ a) {
        for (int b = 0; b < 5; ++ b) {
            for (int c = 0; c < 5; ++ c) {
                for (int d = 0; d < 5; ++ d) {
                    sum += dp_cur.dp[a][b][c][d];
                }
            }
        }
    }
    cout << sum % MOD << endl;
    return 0;
}