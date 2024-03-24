#include "include.h"


int main() {
    vector<vector<char>> board = {{'O','O','O'},{'O','O','O'},{'O','O','O'}};
    vector<vector<int>> grid = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    vector<vector<int>> edges = {{1,2}, {1,3}, {2,3}};
    findRedundantConnection(edges);
    return 0;
}