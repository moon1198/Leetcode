#include <bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> a, vector<int> b) {
    if (a.empty()) {
        return b;
    } else if (b.empty()) {
        return a;
    }
    vector<int> ans;
    int idx1 = 0, idx2 = 0;
    while (idx1 < a.size() && idx2 < b.size()) {
        if (a[idx1] < b[idx2]) {
            ans.push_back(a[idx1]);
            ++ idx1;
        } else {
            ans.push_back(b[idx2]);
            ++ idx2;
        }
    }
    if (idx1 == a.size()) {
        while (idx2 < b.size()) {
            ans.push_back(b[idx2]);
            ++ idx2;
        }
    } else {
        while (idx1 < a.size()) {
            ans.push_back(a[idx1]);
            ++ idx1;
        }
    }
    return ans;
}

vector<int> fen(vector<int> &nums, int l, int r) {
    vector<int> ans;
    if (r - l == 0) {
        return ans;
    }
    if (r - l == 1) {
        ans.push_back(nums[l]);
        return ans;
    }
    int m = l + ((r - l) >> 1);
    vector<int> left = fen(nums, l, m);
    vector<int> right = fen(nums, m, r);
    return merge(left, right);
}

vector<int> quick_sort(vector<int> nums) {

    int l = 0, r = nums.size();
    return fen(nums, l, r);
}