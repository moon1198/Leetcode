#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

static vector<vector<int>> res;
static vector<int> tmp;

void recur90_0(vector<int> &nums, int index) {
    if (index >= static_cast<int>(nums.size())) return ;

    for (int i = index; i < static_cast<int>(nums.size()); ++ i) {
        if (i > index && nums[i] == nums[i - 1]) {
            continue;
        }
        tmp.push_back(nums[i]);
        res.push_back(tmp);
        recur90_0(nums, i + 1);
        tmp.pop_back();
    }
}

vector<vector<int>> solution90_0(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    res.push_back(tmp);
    recur90_0(nums, 0);
    return res;
}