#include <bits/stdc++.h>
using namespace std;

vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
    //暴力
    //time : O(n2)

    vector<int> ans(2, -1);
    int n = nums.size();
    for (int i = 0; i < n; ++ i) {
        for (int j = i + indexDifference; j < n; ++ j) {
            if (abs(nums[i] - nums[j]) >= valueDifference) {
                ans[0] = i;
                ans[1] = j;
            }
        }
    }

    return ans;
}

vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
    //全记录，更慢了
    int n = nums.size();
    vector<int> ans(2, -1);
    vector<vector<int>> dict(n);
    int mi = n - 1, mx = n - 1;
    for (int i = n - 1; i >= indexDifference; -- i) {
        if (nums[i] > nums[mx]) {
            mx = i;
        } else if (nums[i] < nums[mi]) {
            mi = i;
        }
        dict[i - indexDifference].push_back(mi);
        dict[i - indexDifference].push_back(mx);
    }
    for (int i = 0; i < n - indexDifference; ++ i) {
        if (abs(nums[i] - nums[dict[i][0]]) >= valueDifference) {
            ans[0] = i;
            ans[1] = dict[i][0];
            break;
        } else if (abs(nums[i] - nums[dict[i][1]]) >= valueDifference) {
            ans[0] = i;
            ans[1] = dict[i][1];
            break;
        }
    }

    return ans;
}

vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
    int n = nums.size();
    int r = n - 1, l = n - 1 - indexDifference;
    int mi = n - 1, mx = n - 1;
    for(; l >= 0; --r, --l) {
        if (nums[r] > nums[mx]) {
            mx = r;
        } else if (nums[r] < nums[mi]) {
            mi = r;
        }
        if (abs(nums[l] - nums[mi]) >= valueDifference) {
            return {l, mi};
        } else if (abs(nums[l] - nums[mx]) >= valueDifference) {
            return {l, mx};
        }
    }

    return {-1, -1};
}