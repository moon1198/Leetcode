#include <bits/stdc++.h>
using namespace std;

int longestAwesome(string s) {
    //暴力out
    int n = s.size();
    vector<vector<int>> vec(n, vector<int>(10, 0));
    ++vec[0][s[0] - '0'];
    for (int i = 1; i < n; ++i) {
        vec[i] = vec[i - 1];
        ++vec[i][s[i] - '0'];
    }
    int ans = 0;
    for (int i = 0; i < n; ++ i) {
        bool check = true;
        bool flag = false;
        for (int k = 0; k < 10; ++ k) {
            if (vec[i][k] % 2 == 0) {
                continue;
            } else if (vec[i][k] % 2 == 1) {
                if (flag) {
                    check = false;
                    break;
                } else {
                    flag = true;
                    // cout << i << "; " << j << "; " <<  ans << endl;
                }
            }
        }
        if (check) {
            ans = max(ans, i + 1);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            bool check = true;
            bool flag = false;
            for (int k = 0; k < 10; ++k) {
                if ((vec[j][k] - vec[i][k]) % 2 == 0) {
                    continue;
                } else if ((vec[j][k] - vec[i][k]) % 2 == 1) {
                    if (flag) {
                        check = false;
                        break;
                    } else {
                        flag = true;
                        // cout << i << "; " << j << "; " <<  ans << endl;
                    }
                }
            }
            if (check) {
                ans = max(ans, j - i);
            }
        }
    }

    return ans;
}

#define D 10
//偶数条件下，相减后满足
//奇数条件下，修改一位后满足条件
int longestAwesome(string s) {
    int n = s.size();
    //index : key , 
    vector<int> pos(1 << D, n);
    //prev == 0 或处理后为0，索引加一
    pos[0] = -1;

    int prev = 0;
    int ans = 0;
    for (int i = 0; i < n; ++ i) {
        prev ^= 1 << s[i] - '0';
        ans = max(ans, i - pos[prev]);
        for (int j = 0; j < D; ++ j) {
            ans = max(ans, i - pos[prev ^ (1 << j)]);
        }

        if (pos[prev] == n) {
            pos[prev] = i;
        }
    }
    return ans;
}