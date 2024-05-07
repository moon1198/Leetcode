#include <bits/stdc++.h>
using namespace std;

//int ans = 0;

//void backtrack(vector<unordered_map<int, int>> dict, int idx, int prev, int &sum) {
    //if (idx <= 0) {
        //ans = max(ans, sum);
        //return ;
    //}
    //bool flag = false;
    //for (auto &it : dict[idx]) {
        //if (it.first != prev) {
            //flag = true;
            //sum += it.second;
            //backtrack(dict, idx - 1, it.first, sum);
            //sum -= it.second;
        //}
    //}
    //if (!flag) {
        //backtrack(dict, idx - 1, -2, sum);
    //}
//}


//int minimumOperations(vector<vector<int>>& grid) {
    //int m = grid.size(), n = grid[0].size();

    //vector<vector<int>>dict(n, vector<int>(10, 0));
    ////vector<unordered_map<int, int>> dict(n + 2);
    ////dict[0][-1] = m; dict[n + 1][-2] = m; 

    //for (int i = 0; i < m; ++ i) {
        //for (int j = 0; j < n; ++ j) {
            //++ dict[j][grid[i][j]];
        //}
    //}
    //vector<vector<int>>dic2(n, vector<int>(4, 0));
    //for (int i = 0; i < n; ++ i) {
        //for (int j = 0; j < 10; ++ j) {
            //if (dict[i][j] > dic2[i][3]) {
                //if (dict[i][j] > dic2[i][1]) {
                    //dic2[i][0] = j;
                    //dic2[i][1] = dict[i][j];
                //} else {
                    //dic2[i][2] = j;
                    //dic2[i][3] = dict[i][j];
                //}
            //} else {
            //}
        //}
    //}
    //if (n == 1) {
        //return m - dic2[0][1];
    //}
    //int prev = dic2[0][0];
    //int sum = dic2[0][1];
    //for (int i = 1; i < dic2.size(); ++ i) {
        //if (dic2[i][0] == prev) {
            //sum += dic2[i][3];
            //prev = dic2[i][2];
        //} else {
            //sum += dic2[i][1];
            //prev = dic2[i][0];
        //}
    //}

    ////int sum = 0;
    ////backtrack(dict, n, -2, sum);
    //return m * n - sum;
//}

int minimumOperations(vector<vector<int>>& grid) {

    //dp[i][j] = max(dp[i -1][when idx != j]) + dp[i][j]

    int m = grid.size(), n = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(10, 0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            ++dp[j][grid[i][j]];
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 10; ++j) {
            int tmp = 0;
            for (int k = 0; k < 10; ++k) {
                if (k != j) {
                    tmp = max(tmp, dp[i - 1][k]);
                }
            }
            dp[i][j] += tmp;
        }
    }
    int sum = 0;
    for (int i = 0; i < 10; ++i) {
        sum = max(sum, dp.back()[i]);
    }
    return m * n - sum;
}

int minimumOperations(vector<vector<int>>& grid) {

    //简化
    //记录了每一层最优解，省略寻优环节
    //dp[i][j] = max(dp[i -1][when idx != j]) + dp[i][j]
    int m = grid.size(), n = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(10, 0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            ++dp[j][grid[i][j]];
        }
    }
    int f0 = 0, f1 = 0, prev = -1;
    for (int i = 0; i < n; ++ i) {
        int x0 = 0, x1 = 0, val = -1;
        for (int j = 0; j < 10; ++ j) {
            int res = dp[i][j] + (j == prev ? f1 : f0);
            if (res > x0) {
                x1 = x0;
                x0 = res;
                val = j;
            } else if (res > x1) {
                x1 = res;
            }
        }
        f0 = x0;
        f1 = x1;
        prev = val;
    }
    return m * n - f0;
}