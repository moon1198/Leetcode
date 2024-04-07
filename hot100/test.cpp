#include <stdio.h>

const int M = 12, mod = 998244353;

int n, m, ans, g[2][M][M][M][M];

int bar() {
    scanf("%d %d", &n, &m);
    int p = 1, q = 0;
    for (int a = p; a < 10; a += 2)
        for (int b = q; b < 10; b += 2)
            for (int c = p; c < 10; c += 2)
                for (int d = q; d < 10; d += 2) {
                    g[0][a + 2][b][c][d] = g[0][a][b][c][d] + (a + b + c + d <= m);
                }
    for (int i = 5; i <= n; ++i) {
        p ^= 1, q ^= 1;
        for (int a = p; a < 10; a += 2)
            for (int b = q; b < 10; b += 2)
                for (int c = p; c < 10; c += 2)
                    for (int d = q; d < 10; d += 2) {
                        int f = m - a - b - c - d;
                        if (q != (f & 1)) --f;
                        if (f > 8 + p) f = 8 + q;
                        g[i & 1][a + 2][b][c][d] = (g[i & 1][a][b][c][d] + (f < q ? 0 : g[~i & 1][f + 2][a][b][c])) % mod;
                    }
    }
    for (int b = q; b < 10; b += 2)
        for (int c = p; c < 10; c += 2)
            for (int d = q; d < 10; d += 2) {
                int f = m - b - c - d;
                if (f < p) continue;
                if (p != (f & 1)) --f;
                if (f > 8 + p) f = 8 + p;
                ans = (ans + g[n & 1][f + 2][b][c][d]) % mod;
            }
    printf("%d", ans);
    return 0;
}
