#include <bits/stdc++.h>
using namespace std;

string decodeString0(string s) {
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


string decodeString(string s) {
    string res;
    stack<int> nums; stack<string> strs;

    int num = 0;
    for (int i = 0; i < s.size(); ++ i) {
        if (s[i] >= '0' && s[i] <= '9') {
            num = 10 * num + (s[i] - '0');
        } else if (s[i] == '[') {
            //遇到数字，是嵌套的开始
            nums.push(num);
            num = 0;
            strs.push(res);
            res = "";
        } else if (s[i] >= 'a' && s[i] <= 'z') {
            res += s[i];
        } else if (s[i] == ']') {
            int times = nums.top();
            nums.pop();
            for (int j = 0; j < times; ++ j) {
                strs.top() += res;
            }
            res = strs.top();
            strs.pop();
        } else {
            //cannot reach here;
        }
    }
    assert(strs.empty());
    // cout << res << endl;
    return res;
}