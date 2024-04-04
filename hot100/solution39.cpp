#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void backtrack(vector<int> &candidates, int idx, int target, vector<int> &path, int sum) {
    if (sum == target) {
        ans.push_back(path);
    }
    if (idx >= candidates.size() || sum > target || path.size() >= 150) return ;
    for (int i = idx; i < candidates.size(); ++ i) {
        path.push_back(candidates[i]);
        sum += candidates[i];
        backtrack(candidates, i, target, path, sum);
        sum -= candidates[i];
        path.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> path;
    backtrack(candidates, 0, target, path, 0);
    return ans;
}