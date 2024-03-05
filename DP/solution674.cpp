#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int solution674_0(vector<int>& nums) {
    int res = 1;
    int cnt = 1;
    for (int i = 1; i < nums.size(); ++ i) {
        if (nums[i] > nums[i - 1]) {
            cnt ++;
        }else {
            cnt = 1;
        }
        res = max(res, cnt);
    }
    return res;
}

int solution674_1(vector<int>& nums) {
    vector<int>dp(nums.size(), 1);
    int res = 1;
    for (int i = 1; i < nums.size(); ++ i) {
        if (nums[i] > nums[i - 1]) {
            dp[i] = dp[i - 1] + 1;
        }
        res = max(dp[i], res);
    }
    return res;
}