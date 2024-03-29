#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int ans = nums[0];
    int sum = 0;
    for (int &num : nums) {
        sum += num;
        if (sum >= 0) {
            ans = max(ans, sum); 
        } else {
            ans = max(ans, sum); 
            sum = 0;
        }
    }
    return ans;
}