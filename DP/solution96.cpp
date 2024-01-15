#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int solution_96(int n) {
    vector<int> dp(n + 1, 1);
    for (int i = 2; i < n + 1; ++ i) {
        int tmp = 0;
        for (int j = 0; j < i; ++ j) {
            tmp += dp[j] * dp[i - j - 1];
        }
        dp[i] = tmp;
    }
    return dp[n];
}