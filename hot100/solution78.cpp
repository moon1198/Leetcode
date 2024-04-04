#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> vec;

void recur(vector<int> &nums, int begin, vector<int> &path) {
    if (begin >= nums.size()) {
        return ;
    }
    for (int i = begin; i < nums.size(); ++ i) {
        path.push_back(nums[i]);
        vec.push_back(path);
        recur(nums, begin + 1, path);
        path.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {

    vector<int> path;
    vec.push_back(path);
    recur(nums, 0, path);
    return vec;
}