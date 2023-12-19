#include <vector>
#include <unordered_map>
#include <algorithm>
using std::vector;
using std::unordered_map;



vector<vector<int>> solution15_0(vector<int> &nums) {
    unordered_map<int, vector<vector<int>>>mp;
    int len = nums.size();
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (mp.count(nums[i] + nums[j])){
                mp[nums[i] + nums[j]].push_back({i, j});
            }else {
                mp.emplace(nums[i] + nums[j], vector<vector<int>>{{i, j}});
            }
        }
    }
    vector<vector<int>>ans;
    for (int i = 0; i < len; ++i) {
        //查找mp表
        if (mp.count(-nums[i])) {
            for (auto &vec : mp[-nums[i]]) {
                if (i != vec[0] && i != vec[1]) {
                    if (i > vec[1]) {
                        ans.push_back({nums[vec[0]], nums[vec[1]], nums[i]});
                    }else if(i < vec[0]) {
                        ans.push_back({nums[i], nums[vec[0]], nums[vec[1]]});
                    }else{
                        ans.push_back({nums[vec[0]], nums[i], nums[vec[1]]});
                    }
                }
            }
        }
    }
    
    return ans;
}


vector<vector<int>> solution15_1(vector<int> &nums) {
    vector<vector<int>>ans;
    int i, left, right, len;
    len = nums.size();
    std::sort(nums.begin(), nums.end());
    for (i = 0; i < len - 2; ++ i) {
        if (nums[i] > 0) {
            break;
        }
        left = i + 1;
        right = len - 1;
        while (left < right){
            if (nums[i] + nums[left] + nums[right] > 0) {
                -- right;
            }else if (nums[i] + nums[left] + nums[right] < 0) {
                ++ left;
            }else {
                ans.push_back({nums[i], nums[left], nums[right]});
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
    return ans;
}