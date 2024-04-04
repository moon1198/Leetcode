#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> vec;
unordered_set<int> st;

void recur(vector<int> &nums, vector<int> &path) {
    //path.size()表示深度
    //set用于查询是否使用
    if (path.size() == nums.size()) {
        vec.push_back(path);
        return;
    }
    for (int i = 0; i < nums.size(); ++ i) {
        if (st.find(nums[i]) == st.end()) {
            path.push_back(nums[i]);
            st.insert(nums[i]);
            recur(nums, path);
            st.erase(nums[i]);
            path.pop_back();
        }
    }

}

vector<vector<int>> permute(vector<int>& nums) {
    vector<int> path;
    recur(nums, path);
    return vec;
}