#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int kama57_0() {
    int n, m;
    cin >> n >> m;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    //包
    for (int i = 2; i < n + 1; ++ i) {
        //单次爬楼梯数，应小于n，
        //对于过程中的台阶数，可以出现一步登天的方案
        //默认n > m;所以j <= m,确保了j < n;
        //物品
        for (int j = 1; j <= i && j <= m; ++ j) {
            dp[i] += dp[i - j];
        }
    }
    for (auto it : dp) {
        cout << it << "; ";
    }
    cout << endl;
    cout << endl;
    cout << dp.back() << endl;
    return dp.back();
}