#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

static vector<vector<string>>res;

bool isVaild51(vector<string> path, int row, int col, int size) {
    for (int i = 0; i < row; ++ i) {
        if (path[i][col] == 'Q') {
            return false;
        }
    }

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; -- i, -- j) {
        if (path[i][j] == 'Q') {
            return false;
        }
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j <= size; -- i, ++ j) {
        if (path[i][j] == 'Q') {
            return false;
        }
    }
    return true;
}

void recur51_0(vector<string> path, int row, int col) {
    if (row == col) {
        res.push_back(path);
        return ;
    }

    for (int i = 0; i < col; ++ i) {
        if (isVaild51(path, row, i, col)) {
            path[row][i] = 'Q';
            recur51_0(path, row + 1, col);
            path[row][i] = '.';
        }
    }
}

vector<vector<string>> solution51_0(int n) {
    res.clear();
    vector<string> path(n, string(n, '.'));
    recur51_0(path, 0, n);

    cout << n << "X" << n << endl;
    for (auto it : res) {
        for (string i : it) {
            cout << i << endl;
        }
        cout << endl;
    }
    return res;
}