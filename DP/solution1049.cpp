#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int solution1049_0(vector<int> &stones) {
    int sum = accumulate(stones.begin(), stones.end(), 0);
    int target = sum / 2;
    vector<int> dp(target + 1, 0);
    for (int i = 0; i < stones.size(); ++ i) {
        for (int j = target; j >= 0; -- j) {
            if (j >= stones[i]) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        for (auto &num : dp) {
            cout << num << "; ";
        }
        cout << endl;
    }
    return sum - 2 * dp.back();
}