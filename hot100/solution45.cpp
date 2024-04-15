#include <bits/stdc++.h>
using namespace std;

int jump0(vector<int>& nums) {
    //dp
    vector<int> dp(nums.size(), INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < nums.size(); ++ i) {
        for (int j = i + 1; j < nums.size() && j <= i + nums[i]; ++ j) {
            dp[j] = min(dp[j], dp[i] + 1);
        }
    }
    return dp[nums.size() - 1];
}

int jump1(vector<int>& nums) {
    int r_edge = 0;
    int n_edge = nums[0];

    int ret = 0;
    for (int i = 0; i < nums.size(); ++ i) {
        if (i > r_edge) {
            ++ ret;
            r_edge = n_edge;
        }
        n_edge = max(n_edge, i + nums[i]);
    }

    return ret;
}   

int jump(vector<int>& nums) {
    //若到达nums.size() - 2; 若没有+ 1， 则当前跳必然到达nums.size() - 1;
    //若+1, 则进入的新一跳必然可达终点
    int len = nums.size();
    int cur = 0;
    int next = nums[0];
    int counts = 0;
    for (int i = 0; i < len - 1; ++ i) {
        next = i + nums[i] > next ? i + nums[i] : next;
        if (i == cur) {
            cur = next;
            ++ counts;
        }
    }
    return counts;
}