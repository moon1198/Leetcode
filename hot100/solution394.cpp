#include <bits/stdc++.h>
using namespace std;

string decodeString(string s) {
    stack<char> stk;
    string ans;
    for (int i = 0; i < s.size(); ++ i) {
        if (s[i] == ']') {
            string tmp_str;
            while (stk.top() != '[') {
                tmp_str = stk.top() + tmp_str;
                stk.pop();
            }
            stk.pop();

            //
            int times = 0, exp = 0;
            while (!stk.empty() && (stk.top() >= '0' && stk.top() <= '9')) {
                times += pow(10, exp ++) * (stk.top() - '0');
                stk.pop();
            }
            string tmp = tmp_str;
            for (int j = 0; j < times - 1; ++ j) {
                tmp_str += tmp;
            }

            //combine
            while (!stk.empty() && (stk.top() >= 'a' && stk.top() <= 'z')) {
                tmp_str = stk.top() + tmp_str;
                stk.pop();
            }
            if (stk.empty()) {
                ans += tmp_str;
                tmp_str.clear();
            } else {
                //rewrite to stack
                for (int j = 0; j < tmp_str.size(); ++ j) {
                    stk.push(tmp_str[j]);
                }
            }
        } else if (stk.empty() && (s[i] >= 'a' && s[i] <= 'z')) {
            ans += s[i];
        } else {
            stk.push(s[i]);
        }
    }
    // cout << ans << endl;
    return ans;
}