#include <bits/stdc++.h>

using namespace std;

int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
void recur130_0(vector<vector<char>>& grid, int i, int j) {
    grid[i][j] = 'X';
    for (int k = 0; k < 4; ++ k) {
        int nextx = i + dir[k][0];
        int nexty = j + dir[k][1];
        if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) {
            continue;
        }else {
            if (grid[nextx][nexty] == 'O') {
                recur130_0(grid, nextx, nexty);
            }
        }
    }

}

void solve(vector<vector<char>>& board) {
    vector<vector<char>> grid_cp(board.begin(), board.end());
    for (int i = 0; i < grid_cp[0].size(); ++ i) {
        if (grid_cp[0][i] == 'O') {
            recur130_0(grid_cp, 0, i);
        }
        if (grid_cp[grid_cp.size() - 1][i] == 'O') {
            recur130_0(grid_cp, grid_cp.size() - 1, i);
        }
    }
    for (int i = 1; i < grid_cp.size() - 1; ++ i) {
        if (grid_cp[i][0] == 'O') {
            recur130_0(grid_cp, i, 0);
        }
        if (grid_cp[i][grid_cp[0].size() - 1] == 'O') {
            recur130_0(grid_cp, i, grid_cp[0].size() - 1);
        }
    }

    for (int i = 0; i < grid_cp.size(); ++ i) {
        for (int j = 0; j < grid_cp[0].size(); ++ j) {
            if (board[i][j] == 'O' && grid_cp[i][j] == 'O') {
                board[i][j] = 'X';
            }
        }
    }
}