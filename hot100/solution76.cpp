#include <bits/stdc++.h>
using namespace std;

int idx(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch - 'A' + 26;
    }
    return ch - 'a'; 
}

string minWindow(string s, string t) {
    int left = 0, right = 0;
    int n = s.size();
    string ans = "";
    int flag = 0;
    
    vector<int> vec(26 * 2, 0);
    for (int i = 0; i < t.size(); ++ i) {
        if (++ vec[idx(t[i])] == 1) {
            ++ flag;
        }
    }
    //有flag种字母被需求
    for (; right < n; ++ right) {
        //只有有需求的字母可以走向flag == 0
        if (vec[idx(s[right])] > 0) {
            if (-- vec[idx(s[right])] == 0) {
                -- flag;
            }
        } else {
            -- vec[idx(s[right])];
            continue;
        }

        while (flag == 0) {
            ans = (ans.size() < (right - left + 1)) && !ans.empty() ? ans : s.substr(left, right - left + 1);
            if (vec[idx(s[left])] == 0) {
                ++ flag;
            }
            ++ vec[idx(s[left])];
            ++ left;
        }
    }
    return ans;
}