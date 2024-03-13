#include <stack>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int trap1(vector<int>& height) {
    int ans = 0;
    for (int i = 1; i < height.size() - 1; ++ i) {
        int left = 0;
        int right = 0;
        for (int j = i; j >= 0; -- j) {
            left = max(left, height[j]);
        }
        for (int j = i; j < height.size(); ++ j) {
            right = max(right, height[j]);
        }
        ans += min(left, right) - height[i];
    }
    return ans;
}

int trap2(vector<int>& height) {
    int ans = 0;
    stack<int> stk;

    for (int i = 0; i < height.size(); ++ i) {
        while (!stk.empty() && height[i] > height[stk.top()]) {
            int mid = height[stk.top()];
            stk.pop();
            if (!stk.empty()) {
                ans += (min(height[i], height[stk.top()]) - mid) * (i - stk.top() - 1);
            }
        }
        stk.push(i);
    }
    return ans;
}