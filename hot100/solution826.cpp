#include <bits/stdc++.h>
using namespace std;

int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    unordered_map<int, int> mp;
    unordered_map<int, int> mp1;
    int n = difficulty.size();  int m = worker.size();

    for (int i = 0; i < n; ++ i) {
        //添加map时，注意覆盖问题
        if (mp1.find(difficulty[i]) == mp1.end()) {
            mp1[difficulty[i]] = profit[i];
        } else {
            mp1[difficulty[i]] = max(profit[i], mp1[difficulty[i]]);
        }
    }
    sort(difficulty.begin(), difficulty.end());
    int mx = 0;
    for (int i = 0; i < n; ++ i) {
        mx = max(mx, mp1[difficulty[i]]);
        mp[difficulty[i]] = mx;
    }

    int ans = 0;
    //int prev = 0;
    for (int i = 0; i < m; ++ i) {
        int l = 0, r = n - 1;
        int tmp = worker[i];
        while (l <= r) {
            int m = (l + r) / 2;
            if (tmp == difficulty[m]) {
                ans += mp[difficulty[m]];
                break;
            } else if (tmp < difficulty[m]) {
                r = m - 1;
            } else if (tmp > difficulty[m]) {
                l = m + 1;
            }
        }
        if (l > r) {
            if (r < 0) {
                ans += tmp > difficulty[0] ? profit[0] : 0;
            } else if (l == n) {
                ans += tmp > difficulty[n - 1] ? mp[difficulty[n - 1]] : 0;
            }else if (tmp > difficulty[l]) {
                ans += mp[difficulty[l]];
            } else {
                ans += mp[difficulty[r]];
            }
        }
        //cout << tmp << "; " << ans - prev << endl;
        //prev = ans;
    }
    return ans;
}

int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    vector<pair<int, int>> mp;
    int n = difficulty.size();  int m = worker.size();

    for (int i = 0; i < n; ++ i) {
        mp.push_back({difficulty[i], profit[i]});
    }
    sort(mp.begin(), mp.end(), [](pair<int, int> x1, pair<int, int> x2)
            {return x1.first < x2.first || (x1.first == x2.first && x1.second < x2.second);});
    sort(worker.begin(), worker.end());

    int j = 0, ans = 0;
    int mx = 0;
    for (int i = 0; i < m; ++ i) {
        while (j < n && worker[i] >= mp[j].first) {
            mx = max(mx, mp[j].second);
            ++ j;
        }
        ans += mx;
    }
    return ans;
}
