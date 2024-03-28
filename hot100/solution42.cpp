#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
    int ans = 0;
    stack<int>stk;
    int n = height.size();
    if (n < 3) {
        return 0;
    }
    stk.push(0);
    for (int i = 1; i < n; ++ i) {
        while (!stk.empty() && height[i] > height[stk.top()]) {
            int mid = stk.top();
            stk.pop();
            if (!stk.empty()) {
                int tmp = (min(height[i], height[stk.top()]) - height[mid]) * (i - stk.top() - 1);
                ans += tmp;
            }
        }
        stk.push(i);
    }
    return ans;
}