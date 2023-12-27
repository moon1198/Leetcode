#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;


static vector<vector<int>> res;
static vector<int> tmp;


void recur78_0(vector<int> &nums, int index) {
    if (index >= static_cast<int>(nums.size())) {
        return;
    }
    for (int i = index; i < static_cast<int>(nums.size()); ++ i) {
        tmp.push_back(nums[i]);
        res.push_back(tmp);
        recur78_0(nums, i + 1);
        tmp.pop_back();
    }
}

vector<vector<int>> solution78_0(vector<int> &nums) {
    res.push_back(tmp);
    recur78_0(nums, 0);
    return res;
}