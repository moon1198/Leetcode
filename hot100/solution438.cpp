#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &vec) {
    for (int i = 0; i < vec.size(); ++ i) {
        if (vec[i] != 0) {
            return false;
        }
    }
    return true;
}

vector<int> findAnagrams(string s, string p) {
    if (s.size() < p.size()) 
        return {};
    vector<int> ans;
    vector<int>vec(26, 0);
    for (auto &it : p) {
        ++ vec[it - 'a'];
    }

    int m = p.size();
    int n = s.size();
    int right = m, left = 0;
    for (int i = 0; i < m; ++ i) {
        -- vec[s[i] - 'a'];
    }
    if (check(vec)) {
        ans.push_back(0);
    }

    for (; right < n; ++ right, ++ left) {
        -- vec[s[right] - 'a'];
        ++ vec[s[left] - 'a'];
        if (check(vec)) {
            ans.push_back(left + 1);
        }
    }
    return ans;
}