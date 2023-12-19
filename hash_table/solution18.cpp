#include <vector>
#include <unordered_map>
#include <algorithm>
using std::vector;
using std::unordered_map;

vector<vector<int>> solution18_0(vector<int> &nums, int target) {
    vector<vector<int>>ans;
    int i, left, right, len;
    len = nums.size();
    std::sort(nums.begin(), nums.end());
    for (int j = 0; j < len - 3; ++ j) {
        if (nums[j] > 0 && nums[j] >= target) {
            break;
        }
        for (i = j + 1; i < len - 2; ++ i) {
            left = i + 1;
            right = len - 1;
            while (left < right){
                if ((long)nums[j] + nums[i] + nums[left] + nums[right] > target) {
                    -- right;
                }else if ((long)nums[j] + nums[i] + nums[left] + nums[right] < target) {
                    ++ left;
                }else {
                    ans.push_back({nums[j], nums[i], nums[left], nums[right]});
                    while (left + 1 < right && nums[left + 1] == nums[left]) {
                        ++ left;
                    }
                    ++ left;
                    while (right - 1 > left && nums[right - 1] == nums[right]) {
                        -- right;
                    }
                    -- right;
                }
            }
            while (i + 1 < len - 2 && nums[i + 1] == nums[i]) {
                ++ i;
            }
        }
        while (j + 1 < len - 3 && nums[j + 1] == nums[j]) {
            ++ j;
        }
    }
    return ans;
}