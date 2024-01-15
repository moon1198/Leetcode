#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int solution494_0(vector<int> &nums, int target) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum < abs(target)) return 0;
    if ((sum - abs(target)) % 2 == 1) return 0;
    int my_tar = (sum - abs(target)) / 2;

    vector<int> dp(my_tar + 1, 0);
    dp[0] = 1;
    //for (auto &num : nums) {
    //    if (num == 0) {
    //        dp[0] *= 2;
    //    }
    //}
    for (int i = 0; i < nums.size(); ++ i) {
        for (int j = my_tar; j >= 0; -- j) {
            if (j >= nums[i]) {
                //dp[j] = max(dp[j], dp[j - nums[i]] * (dp[nums[i]] + 1));
                dp[j] += dp[j - nums[i]];
            }
        }
        for (auto &num : dp) {
            cout << num << "; ";
        }
        cout << endl;
        
    }
    return dp.back();
}