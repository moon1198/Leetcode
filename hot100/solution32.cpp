#include <bits/stdc++.h>
using namespace std;

int longestValidParentheses(string s) {
    int n = s.size();
    vector<bool> dict(n, false);
    stack<int> stk;
    for (int i = 0; i < n; ++ i) {
        if (!stk.empty() && s[i] == ')' && s[stk.top()] != s[i]) {
            dict[i] = true;
            dict[stk.top()] = true;
            stk.pop();
        } else {
            stk.push(i);
        }
    }
    int ans = 0;
    int tmp = 0;
    for (int i = 0; i < n; ++ i) {
        if (dict[i]) {
            ++ tmp;
        } else {
            ans = max(ans, tmp);
            tmp = 0;
        }
    }
    ans = max(ans, tmp);

    return ans;
}