#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> mp;

void primes(int num, int idx) {
    for (int i = 2; i <= num / i; ++ i) {
        if (num % i == 0) {
            mp[i].push_back(idx);
        }
        while (num % i == 0) {
            num /= i;
        }
    }
    if (num != 1) {
        mp[num].push_back(idx);
    }
}

int bar() {
    int n = 0;
    cin >> n;
    vector<int> vec(n, 0);
    for (int i = 0; i < n; ++ i) {
        int tmp;
        cin >> tmp;
        primes(tmp, i + 1);
    }
    pair<int, int> ans = {INT_MAX, INT_MAX};
    for (auto &it : mp) {
        if (it.second.size() < 2) {
            continue;
        }
        if (ans.first > it.second[0]) {
            ans.first = it.second[0];
            ans.second = it.second[1];
        } else if (ans.first == it.second[0]){
            ans.second = min(ans.second, it.second[1]);
        }
    }
    cout << ans.first << " " << ans.second << endl;

    return 0;
}