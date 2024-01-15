#include <iostream>
#include <vector>

using namespace std;

int kama46_0() {
    
    //read args
    int type = 0, size = 0;
    cin >> type >> size;
    vector<vector<int>> dp(type + 1, vector<int>(size + 1, 0));
    vector<int> cost(type);
    vector<int> value(type);
    for (int i = 0; i < type; ++ i) {
        cin >> cost[i];
    }
    for (int i = 0; i < type; ++ i) {
        cin >> value[i];
    }
    
    //begin computing
    for (int i = 1; i < type + 1; ++ i) {
        for (int j = 1; j < size + 1; ++ j) {
            if (cost[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], value[i - 1] + dp[i - 1][j - cost[i - 1]]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    
    //for (int i = 1; i < type + 1; ++ i) {
    //    for (int j = size; j > 0; -- j) {
    //        if (cost[i - 1] <= j) {
    //            dp[j] = max(dp[j], value[i - 1] + dp[j - cost[i - 1]]);
    //        }
    //    }
    //}
    
    ////output
    //cout << dp[size];


    //output
    cout << dp[type][size];
    
    return 0;
}