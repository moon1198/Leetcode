#include <bits/stdc++.h>
using namespace std;

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
bool backtrack
(vector<vector<char>>& board, int i, int j, string word, string path, vector<vector<bool>> &used) {
    if (path != word.substr(0, path.size())) return false;
    if (path == word) return true;
    int m = board.size();
    int n = board[0].size();
    for (int k = 0; k < 4; ++ k) {
        int nextx = i + dir[k][0];
        int nexty = j + dir[k][1];
        if (nextx < 0 || nextx >= m || nexty < 0 || nexty >= n || used[nextx][nexty]) continue;
        path.push_back(board[nextx][nexty]);
        used[nextx][nexty] = true;
        if (backtrack(board, nextx, nexty, word, path, used)) {
            return true;
        }
        used[nextx][nexty] = false;;
        path.pop_back();
    }
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    int m = board.size();
    int n = board[0].size();
    string path;
    vector<vector<bool>> used(m, vector<bool>(n, false));
    for (int i = 0; i < m; ++ i) {
        for (int j = 0; j < n; ++ j) {
            path.push_back(board[i][j]);
            used[i][j] = true;
            if (backtrack(board, i, j, word, path, used)) {
                return true;
            }
            used[i][j] = false;;
            path.pop_back();
        }
    }
    return false;
}

bool backtrack
(vector<vector<char>>& board, int i, int j, string word, vector<vector<bool>> &used, int len) {
    if (board[i][j] != word[len]) return false;
    if (len == word.size() - 1) return true;
    int m = board.size();
    int n = board[0].size();
    for (int k = 0; k < 4; ++ k) {
        int nextx = i + dir[k][0];
        int nexty = j + dir[k][1];
        if (nextx < 0 || nextx >= m || nexty < 0 || nexty >= n || used[nextx][nexty]) continue;
        used[nextx][nexty] = true;
        if (backtrack(board, nextx, nexty, word, used, len + 1)) {
            return true;
        }
        used[nextx][nexty] = false;;
    }
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    int m = board.size();
    int n = board[0].size();
    vector<vector<bool>> used(m, vector<bool>(n, false));
    for (int i = 0; i < m; ++ i) {
        for (int j = 0; j < n; ++ j) {
            used[i][j] = true;
            if (backtrack(board, i, j, word, used, 0)) {
                return true;
            }
            used[i][j] = false;
        }
    }
    return false;
}