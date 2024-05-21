#include <bits/stdc++.h>
using namespace std;

long long sumDigitDifferences(vector<int>& nums) {
    int len = 0;
    while (nums[0] / pow(10, len) >= 1) {
        ++ len;
    }
    int n = nums.size();
    vector<vector<int>> dict(n, vector<int>(len, 0));
    for (int i = 0; i < n; ++ i) {
        for (int m = 0; m < len; ++ m) {
            dict[i][m] = nums[i] % 10;
            nums[i] /= 10;
        }
    }
    long long ans = 0;
    //O(n2)
    //for (int j = 0; j < len; ++ j) {
    //    int tmp = 0;
    //    for (int i = 0; i < n; ++ i) {
    //        for (int k = i + 1; k < n; ++ k) {
    //            if (dict[i][j] != dict[k][j]) {
    //                ++ ans;
    //                ++ tmp;
    //            }
    //        }
    //    }
    //    cout << tmp << endl;
    //}

    //O(n)
    for (int j = 0; j < len; ++ j) {
        vector<int> tmp(10, 0);
        for (int i = 0; i < n; ++ i) {
            ++ tmp[dict[i][j]];
        }
        for (int k = 0; k < 10; ++ k) {
            for (int k1 = k + 1; k1 < 10; ++ k1) {
                ans += tmp[k] * tmp[k1];
            }
        }
    }

    return ans;
    
}