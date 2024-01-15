#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int solution63_0(vector<vector<int>> &obstacleGrid) {
    vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 1));
    for (int i = 0; i < obstacleGrid.size(); ++ i) {
        for (int j = 0; j < obstacleGrid[0].size(); ++ j) {
            if (obstacleGrid[i][j] == 1) {
                dp[i][j] = 0;
                continue;
            } else {
                if (i > 0 && j > 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                } else if (i > 0) {
                    dp[i][j] = dp[i - 1][j];
                } else if (j > 0) {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
    }
    return dp[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
}