#include <bits/stdc++.h>
using namespace std;

int cnt = INT_MAX;

//nums :dict; 
void backtrace(vector<int>& nums, vector<int>& path, vector<bool>& used, int& tmp, vector<int>& vec) {
    int n = nums.size();
    int m = path.size();
    //剪枝，so important
    if (tmp >= cnt) return ;
    if (m == n) {
        tmp += abs(path[m - 1] - nums[path[0]]);
        if (tmp < cnt) {
            cnt = tmp;
            for (int i = 0; i < m; ++ i) {
                vec[i] = path[i];
            }
        }
        tmp -= abs(path[m - 1] - nums[path[0]]);
        return ;
    }
    for (int i = 0; i < n; ++ i) {
        if (!used[i]) {
            used[i] = true;
            path.push_back(i);
            tmp += abs(path[m - 1] - nums[path[m]]);
            backtrace(nums, path, used, tmp, vec);
            tmp -= abs(path[m - 1] - nums[path[m]]);
            path.pop_back();
            used[i] = false;
        }
    }
}

vector<int> findPermutation(vector<int>& nums) {
    int n = nums.size();
    vector<int> vec(n, 0);
    vector<bool> used(n, false);
    vector<int> path;
    int tmp = 0;
    for (int i = 0; i < n; ++ i) {
        if (!used[i]) {
            used[i] = true;
            path.push_back(i);
            backtrace(nums, path, used, tmp, vec);
            path.pop_back();
            used[i] = false;
        }
    }
    return vec;
}