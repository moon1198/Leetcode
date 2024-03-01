#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int solution279_0(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    // int i = 1;
    // while(i * i <= n) {
    //     for (int j = i * i; j < dp.size(); ++ j) {
    //         if (dp[j - i * i] != INT_MAX) {
    //             dp[j] = min(dp[j], dp[j - i * i] + 1);
    //         }
    //     }
    //     ++ i;
    // }
    for (int i = 1; i * i <= n; ++ i){
        for (int j = i * i; j < dp.size(); ++ j) {
            if (dp[j - i * i] != INT_MAX) {
                dp[j] = min(dp[j], dp[j - i * i] + 1);
            }
        }
    }
    return dp.back();
}