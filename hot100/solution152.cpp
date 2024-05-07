#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    for (int i = 1; i < n; ++ i) {
        //0为新的开始，截断
        if (dp[i - 1] == 0) {
            dp[i] = nums[i];
        } else {
            dp[i] = dp[i - 1] * nums[i];
        }
    }
    int ans = INT_MIN, val = 1;
    for (int i = 0; i < n; ++ i) {
        if (dp[i] == 0) {
            //到0后，val重新init，0前的前缀积已无法做除数
            ans = max(ans, dp[i]);
            val = 1;
        } else if (dp[i] > 0){
            ans = max(ans, dp[i]);
        } else {
            ans = max(ans, dp[i] / val);

            //update val
            if (val == 1) {
                val = dp[i];
            } else {
                val = max(val, dp[i]);
            }
        }
    }
    return ans;
}