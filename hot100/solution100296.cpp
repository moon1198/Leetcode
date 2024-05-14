#include <bits/stdc++.h>
using namespace std;

int findPermutationDifference(string s, string t) {
    vector<vector<int>> dict(26, vector<int>(2, 0));
    for (int i = 0; i < s.size(); ++ i) {
        dict[s[i] - 'a'][0] = i;
        dict[t[i] - 'a'][1] = i;
    }
    int ans = 0;
    for (int i = 0; i < 26; ++ i) {
        ans += abs(dict[i][0] - dict[i][1]);
    }
    return ans;
}