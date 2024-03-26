#include "include.h"


int main() {
    vector<vector<char>> board = {{'O','O','O'},{'O','O','O'},{'O','O','O'}};
    vector<vector<int>> grid = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    vector<vector<int>> edges = {{1,2},{2,3},{3,4},{4,1},{1,5}};
    printf("x=%d y=%d", 3);
    return 0;
}