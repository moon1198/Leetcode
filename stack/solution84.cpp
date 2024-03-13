#include <stack>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int largestRectangleArea1(vector<int>& heights) {
    int ans = 0;
    for (int i = 0; i < heights.size(); ++ i) {
        int h = INT_MAX;
        for (int j = i; j < heights.size(); ++ j) {
            h = min(h, heights[j]);
            if (h == 0) break;
            ans = max(ans, h * (j - i + 1));
        }
    }
    return ans;
}

// int largestRectangleArea2(vector<int>& heights) {
//     int ans = 0;
//     stack<int>stk;
//     for (int i = 0; i < heights.size(); ++ i) {
//         while (!stk.empty() && heights[i] < heights[stk.top()]) {
//             //ans = max(ans, heights[stk.top()] * (i - stk.top()));
//             int h = stk.top();
//             stk.pop();
//             ans = max(ans, heights[h] * (h - stk.top()));
//         }
//         stk.push(i);
//     }
//     while (!stk.empty()) {
//         int h = stk.top();
//         stk.pop();
//         if (!stk.empty()) {
//             int area = heights[h] * (h - stk.top());
//             ans = max(ans, area);
//         } else {
//             int area = heights[h] * (h + 1);
//             ans = max(ans, area);
//         }
//     }
//     return ans;

// }


int largestRectangleArea2(vector<int>& heights) {
    int ans = 0;
    stack<int>stk;
    heights.insert(heights.begin(), 0);
    heights.insert(heights.end(), 0);
    for (int i = 0; i < heights.size(); ++ i) {
        while (heights[i] < heights[stk.top()]) {
            int h = heights[stk.top()];
            stk.pop();
            int w = i - stk.top() - 1;
            ans = max(ans, w * h);
        }
        stk.push(i);
    }
    return ans;
}
