#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int solution377_0(vector<int>& nums, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    // //纵向遍历为排序， 横向遍历为组合
    // for (int i = 0; i < nums.size(); ++ i) {
    //     for (int j = nums[i]; j < target + 1; ++ j) {
    //         dp[j] += dp[j - nums[i]];
    //     }
    // }
    for (int i = 1; i <= target; ++ i) {
        for (int j = 0; j < nums.size(); ++ j) {
            //默认组合数溢出int为不可能事件
            if (i >= nums[j] && dp[i] > INT_MAX - dp[i - nums[j]]) {

                cout << i << "; nums[j] = " << nums[j] << endl;
                exit(0);

            }
            if (i >= nums[j] && dp[i] < INT_MAX - dp[i - nums[j]]) {
                dp[i] += dp[i - nums[j]];
                //cout << dp[i] << "; ";
            }
        }
        if (i % 10 == 0)
        cout << "dp[" << i << "] = " << dp[i] << endl;
        //cout << endl;
        //cout << endl;
    }
    return dp.back();
}


//删去log
int solution377_1(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        // //纵向遍历为排序， 横向遍历为组合
        for (int i = 1; i <= target; ++ i) {
            for (int j = 0; j < nums.size(); ++ j) {
                //默认组合数溢出int为不可能事件
                if (i >= nums[j] && dp[i] < INT_MAX - dp[i - nums[j]]) {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp.back();
}