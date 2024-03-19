#include "include.h"


int main() {
    vector<vector<char>> board = {{'O','O','O'},{'O','O','O'},{'O','O','O'}};
    vector<vector<int>> grid = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    islandPerimeter(grid);
    return 0;
}