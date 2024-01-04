#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;


int call_count = 0 ;
bool isVaild37(vector<vector<char>> &board, int i, int j, int val) {
    ++ call_count;
    for (int i = 0; i < 9; ++ i) {
        if (board[i][j] == '0' + val) {
            return false;
        }
    }

    for (int j = 0; j < 9; ++ j) {
        if (board[i][j] == '0' + val) {
            return false;
        }
    }
    int row = i / 3, col = j / 3;

    for (int i = 0; i < 3; ++ i) {
        for (int j = 0; j < 3; ++ j) {
            if (board[row * 3 + i][col * 3 + j] == '0' + val) {
                return false;
            }
        }
    }

    return true;
}

bool recur37_0(vector<vector<char>> &board) {
    for (int i = 0; i < 9; ++ i) {
        for (int j = 0; j < 9; ++ j) {
            if (board[i][j] == '.') {
                for (int val = 1; val < 10; ++ val) {
                    if (isVaild37(board, i, j, val)) {
                        board[i][j] = '0' + val;
                        if (recur37_0(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solution37_0(vector<vector<char>> &board) {
    recur37_0(board);
    cout << "isVaild has been call: " << call_count << "times" << endl;
}