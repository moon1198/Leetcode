#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int solution452_0(vector<vector<int>> &points) {
    sort(points.begin(), points.end(), [](vector<int> &s1, vector<int> &s2) {return s1[0] < s2[0] || (s1[0] == s2[0] && s1[1] < s2[1]); });
    int end = points[0][1];
    int ans = 1;
    for (int i = 0; i < points.size(); ++ i) {
        if (points[i][0] > end) {
            end = points[i][1];
            ++ ans;
            continue;
        }
        end = end < points[i][1] ? end : points[i][1];
    }
    return ans;
}