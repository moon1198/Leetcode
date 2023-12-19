#include <unordered_map>
#include <vector>

using std::vector;
using std::unordered_map;

vector<int> solution1_0(vector<int> &nums, int target) {
    unordered_map<int , int> mp;
    vector<int>ans;
    int len = nums.size();
    for (int i = 0; i < len; ++ i) {
        if (mp.count(target - nums[i])){
            ans.push_back(mp.find(target - nums[i])->second);
            ans.push_back(i);
            return ans;
        }
        mp.emplace(nums[i], i);
    }
    return ans;
}
