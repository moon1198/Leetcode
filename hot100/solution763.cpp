#include <bits/stdc++.h>
using namespace std;

vector<int> partitionLabels(string s) {
    int dict[26] = {0};
    for (int i = 0; i < s.size(); ++ i) {
        dict[s[i] - 'a'] = max(dict[s[i] - 'a'], i);
    }

    vector<int> ans;
    int beg = 0;
    int r_end = dict[s[0] - 'a'];
    for (int i = 0; i < s.size(); ++ i) {
        r_end = max(r_end, dict[s[i] - 'a']);
        if (i == r_end) {
            ans.push_back(r_end - beg + 1);
            beg = i + 1;
            if (i + 1 < s.size()) {
                r_end = dict[s[i + 1] - 'a'];
            }
        }
    }


    int len = 0;
    int r_end = dict[s[0] - 'a'];
    for (int i = 0; i < s.size(); ++ i) {
        ++ len;
        r_end = max(r_end, dict[s[i] - 'a']); 
        if (i == r_end) {
            ans.push_back(len);
            len = 0;
        }
    }

    return ans;
}