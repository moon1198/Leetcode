#include "include.h"

int main() {
    vector<vector<char>>board(9, vector<char>(9, '.'));
    solution37_0(board);
    for (auto it : board) {
        for (auto ch : it) {
            cout << ch << "; ";
        }
        cout << endl;
    }
    return 0;
}