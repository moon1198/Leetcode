#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int solution435(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(), [](vector<int> &s1, vector<int> &s2) {return s1[0] < s2[0] || (s1[0] == s2[0] && s1[1] < s2[1]); });
    int end = intervals[0][1];
    int ans = 0;
    for (int i = 1; i < intervals.size(); ++ i) {
        if (intervals[i][0] < end) {
            //delete the longer one
            end = end < intervals[i][1] ? end : intervals[i][1];
            ++ ans;
            continue;
        }
        end = intervals[i][1];
    }
    return ans;
}