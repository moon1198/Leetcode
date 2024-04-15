#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans(numRows);
    for (int i = 0; i < ans.size(); ++ i) {
        for (int j = 0; j < i + 1; ++ j) {
            ans[i].push_back(1);
        }
    }
    for (int i = 0; i < numRows; ++ i) {
        for (int j = 1; j < i; ++ j) {
            ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
        }
    }
    return ans;
}