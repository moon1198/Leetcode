#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    //空间O(m + n)
    int m = matrix.size();
    int n = matrix[0].size();
    vector<bool> row(m, false);
    vector<bool> col(n, false);
    for (int i = 0; i < m; ++ i) {
        for (int j = 0; j < n; ++ j) {
            if (matrix[i][j] == 0) {
                row[i] = true;
                col[j] = true;
            }
        }
    }
    for (int i = 0; i < m; ++ i) {
        if (row[i]) {
            for (int j = 0; j < n; ++ j) {
                matrix[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; ++ i) {
        if (col[i]) {
            for (int j = 0; j < m; ++ j) {
                matrix[j][i] = 0;
            }
        }
    }
}

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    bool row_flag = false;
    bool col_flag = false;

    for (int i = 0; i < m; ++ i) {
        if (matrix[i][0] == 0) {
            col_flag = true;
        }
    }
    for (int i = 0; i < n; ++ i) {
        if (matrix[0][i] == 0) {
            row_flag = true;
        }
    }

    for (int i = 1; i < m; ++ i) {
        for (int j = 1; j < n; ++ j) {
            if (matrix[i][j] == 0) {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }
    for (int i = 1; i < m; ++ i) {
        for (int j = 1; j < n; ++ j) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
    if (row_flag) {
        for (int i = 0; i < n; ++ i) {
            matrix[0][i] = 0;
        }
    }
    if (col_flag) {
        for (int i = 0; i < m; ++ i) {
            matrix[i][0] = 0;
        }
    }
}
