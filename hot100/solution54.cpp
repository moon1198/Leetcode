#include <bits/stdc++.h>
using namespace std;


vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size(); 
    int n = matrix[0].size();
    int tmp_m = m, tmp_n = n;
    vector<int> ans;
    int idx = 0;
    while (tmp_m > 1 && tmp_n > 1) {
        int i = idx, j = idx;
        for (; j < n - idx - 1; ++ j) {
            ans.push_back(matrix[i][j]);
        }
        for (; i < m - idx - 1; ++ i) {
            ans.push_back(matrix[i][j]);
        }
        for (; j > idx; -- j) {
            ans.push_back(matrix[i][j]);
        }
        for (; i > idx; -- i) {
            ans.push_back(matrix[i][j]);
        }
        tmp_m -= 2;
        tmp_n -= 2;
        ++ idx;
    }
    int i = idx, j = idx;
    for (; j < n - idx; ++ j) {
        ans.push_back(matrix[i][j]);
    }
    for (++ i, -- j; i < m - idx; ++ i) {
        ans.push_back(matrix[i][j]);
    }
    return ans;
}