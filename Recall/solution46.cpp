#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <numeric>

using namespace std;

static vector<vector<int>> res;
static vector<int> path;
static set<int> st;

void recur46_0(vector<int> &nums) {
    if (path.size() == nums.size()) {
        res.push_back(path);
        return ;
    }
    for (int i = 0; i < static_cast<int>(nums.size()); ++ i) {
        if (st.find(nums[i]) == st.end()) {
            path.push_back(nums[i]);
            st.insert(nums[i]);
            recur46_0(nums);
            st.erase(nums[i]);
            path.pop_back();
        }
    }
}

vector<vector<int>> solution46_0(vector<int> &nums) {
    recur46_0(nums);
    return res;
}