#include <bits/stdc++.h>
using namespace std;

int maximumEnergy(vector<int>& energy, int k) {
    //begin from 0 to k
    int n = energy.size();
    vector<int>dp(n, 0);
    for (int i = n - 1; i > n - 1 - k; -- i) {
        int tmp = 0;
        int j = i;
        while (j >= 0) {
            tmp += energy[j];
            dp[j] = tmp;
            j -= k;
        }
    }
    int ans = INT_MIN;
    for (auto &num : dp) {
        ans = max(ans, num);
    }

    return ans;
}