#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
    int n = height.size();
    int left = 0, right = n - 1;
    int ans = 0;
    while (right > left) {
        if (height[right] >= height[left]) {
            ans = max(ans, (right - left) * height[left]);
            ++ left;
        } else {
            ans = max(ans, (right - left) * height[right]);
            -- right;
        }
    }
    return ans;
}