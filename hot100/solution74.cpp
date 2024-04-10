#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int len = m * n;
    int l = 0, r = len;
    while (l < r) {
        //so lower priority for ">>"
        int mid =  l + ((r - l) >> 1);
        int row = mid / n;
        int col = mid % n;
        if (matrix[row][col] == target) {
            return true;
        } else if (matrix[row][col] > target){
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return false;
}