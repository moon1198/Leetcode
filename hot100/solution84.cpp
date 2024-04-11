#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea0(vector<int>& heights) {
    //最大栈
    stack<int> stk;
    heights.insert(heights.begin(), 0);
    heights.insert(heights.end(), 0);
    stk.push(heights[0]);

    int ans = 0;
    for (int i = 1; i < heights.size(); ++ i) {
        //保证栈里至少有两元素
        //使用<；则0高度永不会弹出；
        while (!stk.empty() && heights[i] < heights[stk.top()]) {

            int h = heights[stk.top()];
            stk.pop();
            int w = i - stk.top() - 1;
            ans = max(ans, w * h);
        }
        stk.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int>& heights) {
    //最大栈
    stack<int> stk;
    heights.insert(heights.begin(), 0);
    heights.insert(heights.end(), 0);
    stk.push(heights[0]);

    int ans = 0;
    for (int i = 1; i < heights.size(); ++ i) {
        //保证栈里至少有两元素
        //使用<；则0高度永不会弹出；
        //使用<=；会导致0弹出，stack为空，
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