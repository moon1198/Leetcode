#include <bits/stdc++.h>
using namespace std;

////O(n2)
//vector<int> twoSum(vector<int>& nums, int target) {
//    int n = nums.size();
//    for (int i = 0; i < n; ++ i) {
//        for (int j = i + 1; j < n; ++ j) {
//            if (nums[i] + nums[j] == target) {
//                return {i, j};
//            }
//        }
//    }
//    return {};
//}


//O(n)
//the benfit of map
vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    //key : num; val : index
    unordered_map<int, int>mp;
    for (int i = 0; i < n; ++ i) {
        int tmp = target - nums[i];
        if (mp.find(tmp) != mp.end()) {
            return {i, mp[tmp]};
        }else {
            mp[nums[i]] = i;
        }
    }
    return {};
}