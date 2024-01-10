#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

vector<vector<int>> solution56_0(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(), [](vector<int> &s1, vector<int> &s2) {return s1[0] < s2[0] || (s1[0] == s2[0] && s1[1] < s2[1]); });
    vector<vector<int>> ans;
    int start = intervals[0][0];
    int end = intervals[0][1];
    for (int i = 1; i < intervals.size(); ++ i) {
        if (intervals[i][0] > end) {
            ans.push_back(vector<int>{start, end});
            start = intervals[i][0];
            end = intervals[i][1];
        } else {
            end = max(intervals[i][1], end);
        }
    }
    ans.push_back(vector<int>{start, end});
    return ans;
}