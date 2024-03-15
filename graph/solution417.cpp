#include <bits/stdc++.h>

using namespace std;

int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
void recur417_0(vector<vector<int>>& heights,vector<vector<vector<bool>>>& flag, int i , int j, int index) {
    flag[i][j][index] = true;

    for (int k = 0; k < 4; ++ k) {
        int nextx = i + dir[k][0];
        int nexty = j + dir[k][1];
        if (nextx < 0 || nextx >= heights.size() || nexty < 0 || nexty >= heights[0].size()) {
            continue;
        }else {
            if (heights[nextx][nexty] >= heights[i][j] && !flag[nextx][nexty][index]) {
                recur417_0(heights, flag, nextx , nexty, index);
            }
        }
    }
}
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int m = heights.size();
    int n = heights[0].size();
    //0:paciffc 1:atlnatic
    vector<vector<vector<bool>>> flag(m, vector<vector<bool>>(n, vector<bool>(2, false)));
    vector<vector<int>>ans;

    for (int i = 0; i < n; ++ i) {
        recur417_0(heights, flag, 0 , i, 0);
        recur417_0(heights, flag, m - 1 , i, 1);
    }
    for (int i = 0; i < m; ++ i) {
        recur417_0(heights, flag, i , 0, 0);
        recur417_0(heights, flag, i , n - 1, 1);
    }
    for (int i = 0; i < m; ++ i) {
        for (int j = 0; j < n; ++ j)
            if (flag[i][j][0] && flag[i][j][1]) {
                ans.push_back(vector<int>{i ,j});
            }
    }
    return ans;
}