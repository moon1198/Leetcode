#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <numeric>

using namespace std;

static vector<vector<int>> res;
static vector<int> path;

void recur47_0(vector<int> &nums, vector<bool> used) {
    if (path.size() == nums.size()) {
        res.push_back(path);
        return ;
    }
    set<int> st;
    for (int i = 0; i < static_cast<int>(nums.size()); ++ i) {
        
        if (used[i] || st.find(nums[i]) != st.end()) continue;
        st.insert(nums[i]);
        used[i] = true;
        path.push_back(nums[i]);
        recur47_0(nums, used);
        path.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> solution47_0(vector<int> &nums) {
    // int len = nums.size();
    vector<bool> used(nums.size(), false);
    recur47_0(nums, used);
    return res;
}

void recur47_1(vector<int> &nums, vector<bool> used) {
    if (path.size() == nums.size()) {
        res.push_back(path);
        return ;
    }
    for (int i = 0; i < static_cast<int>(nums.size()); ++ i) {
        //used[i - 1] == true 使相同元素之间产生依赖关系，并产生唯一的拓扑排序
        //select the first equal element each time;
        if (used[i] || (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)) continue;
        used[i] = true;
        path.push_back(nums[i]);
        recur47_1(nums, used);
        path.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> solution47_1(vector<int> &nums) {
    // int len = nums.size();
    vector<bool> used(nums.size(), false);
    sort(nums.begin(), nums.end());
    recur47_1(nums, used);
    return res;
}