#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

bool solution416_0(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 == 1) return false;
    int target = sum / 2;

    vector<int> dp(target + 1, 0);

    for (int i = 0; i < nums.size(); ++ i) {
        for (int j = target; j >= 0; -- j) {
            if (j >= nums[i]) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        //for (int num : dp) {
        //    cout << num << "; ";
        //}
        //cout << endl;
    }
    if (dp.back() == target) return true;
    return false;
}