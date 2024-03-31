#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    //转置后逆序
    int n = matrix.size();
    for (int i = 0; i < n; ++ i) {
        for (int j = i + 1; j < n; ++ j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (auto &it : matrix) {
        reverse(it.begin(), it.end());
    }
}