#include <bits/stdc++.h>
using namespace std;

bool check(vector<string> tmp, int i, int j) {
    int n = tmp.size();

    for (int k = 0; k < i; ++ k) {
        if (tmp[k][j] == 'Q') {
            return false;
        }
    }
    for (int row = i - 1, col = j - 1; row >= 0 && col >= 0; -- row, -- col) {
        if (tmp[row][col] == 'Q') {
            return false;
        }
    }
    for (int row = i - 1, col = j + 1; row >= 0 && col < n; -- row, ++ col) {
        if (tmp[row][col] == 'Q') {
            return false;
        }
    }
    return true;
}

vector<vector<string>> ans;
void backtrack(vector<string> tmp, int row) {
    int n = tmp.size();
    if (row == n) {
        ans.push_back(tmp);
        return ;
    }
    for (int i = 0; i < n; ++ i) {
        if (!check(tmp, row, i)) {
            continue;
        }
        tmp[row][i] = 'Q';
        backtrack(tmp, row + 1);
        tmp[row][i] = '.';
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<string> tmp(n, string (n, '.'));
    backtrack(tmp, 0);
    return ans;
}