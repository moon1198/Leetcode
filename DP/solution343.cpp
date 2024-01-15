#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int solution343_0(int n) {
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i < n + 1; ++ i) {
        int tmp = 0;
        for (int j = 1; j < i; ++ j) {
            tmp = max(tmp, max(j * dp[i - j], j * (i - j)));
        }
        dp[i] = tmp;
    }
    return dp[n];
}