#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

int kama52_0 () {
    //input
    int types, spaces;
    assert(cin >> types >> spaces);
    vector<int>cost(types); vector<int>value(types);
    for (int i = 0; i < types; ++ i) {
        cin >> cost[i] >> value[i];
    }
    
    //compute
    vector<int>dp(spaces + 1, 0);
    for (int i = 0; i < types; ++ i) {
        for (int j = 1; j < spaces + 1; ++ j) {
            if (j >= cost[i]) {
                dp[j] = max(dp[j], dp[j - cost[i]] + value[i]);
            }
        }
    }
    cout << dp.back();
    
    return 0;
    
}