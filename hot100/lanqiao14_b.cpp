#include <bits/stdc++.h>
using namespace std;

int sum = 0;

void dfs(int i, int j, vector<vector<int>> &arr) {

    if (i == 4){
        if (arr[i][0] == 1) {
            ++ sum;
        }
        return ;
    }

    int nexti, nextj; 
    if (j < 5 - i - 1) {
        nexti = i;
        nextj = j + 1;
    } else {
        nexti = i + 1;
        nextj = 1;
    }

    arr[i + 1][j - 1] = arr[i][j] & arr[i][j - 1];
    dfs(nexti, nextj, arr);

    arr[i + 1][j - 1] = arr[i][j] | arr[i][j - 1];
    dfs(nexti, nextj, arr);

    arr[i + 1][j - 1] = arr[i][j] ^ arr[i][j - 1];
    dfs(nexti, nextj, arr);

}



int bar(void) {
    vector<vector<int>> arr(5, vector<int> (5, 0));
    arr[0] = {1, 0, 1, 0, 1};
    dfs(0, 1, arr);
    cout << "sum = " << sum << endl;

    return 0;
}

