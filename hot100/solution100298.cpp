#include <bits/stdc++.h>
using namespace std;

//记忆化非常重要，在dfs中
unordered_map<long long, int> mp;
int dfs(int base, int jump, bool flag, int k) {
    if (base > k + 1) {
        return  0;
    }
    //记录点， base, jump, flag,三个数值才可确定；
    //jump大于等于零，隐藏符号位后，仍可表示唯一性
    long long p = (long long)base << 32 | jump << 1 | flag;
    if (mp.find(p) != mp.end()) {
        return mp[p];
    }
    int res = 0;
    if (base == k) {
        res += 1;
    }

    if (!flag && base > 0) {
        res += dfs(base - 1, jump, true, k);
    }
    res += dfs(base + pow(2, jump), jump + 1, false, k);
    mp[p] = res;
    return res;
}

int waysToReachStair(int k) {
    return dfs(1, 0, false, k);
}