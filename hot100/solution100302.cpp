#include <bits/stdc++.h>
using namespace std;

int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
    int ans = 0;
    vector<vector<int>> dict(26, vector<int>(2, INT_MAX));
    for (int i = 0; i < s.size(); ++ i) {
        int tmp = max(abs(points[i][0]), abs(points[i][1]));
        if (dict[s[i] - 'a'][0] > tmp) {
            dict[s[i] - 'a'][1] = dict[s[i] - 'a'][0];
            dict[s[i] - 'a'][0] = tmp;
        } else if (tmp < dict[s[i] - 'a'][1]) {
            dict[s[i] - 'a'][1] = tmp;
        }
    }
    int flag = INT_MAX;
    for (int i = 0; i < 26; ++ i) {
        flag = min(flag, dict[i][1]);
    }

    for (int i = 0; i < 26; ++ i) {
        if (dict[i][0] < flag) {
            ans ++;
        }
    }

    return ans;
}