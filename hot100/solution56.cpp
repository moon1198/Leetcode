#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](vector<int> &s1, vector<int> &s2) {return s1[0] < s2[0];});
    vector<vector<int>> ans;
    int left = intervals[0][0], right = intervals[0][1];
    for (int i = 1; i < intervals.size(); ++ i) {
        if (intervals[i][0] <= right) {
            right = max(right, intervals[i][1]);
        } else {
            ans.push_back({left, right});
            left = intervals[i][0];
            right = intervals[i][1];
        }
    }
    ans.push_back({left, right});
    return ans;
}