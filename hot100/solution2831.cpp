#include <bits/stdc++.h>
using namespace std;

//int longestEqualSubarray(vector<int>& nums, int k) {
//    int n = nums.size();
//    //key : num ; val : count
//    unordered_map<int, int> mp;
//    for (auto &num : nums) {
//        mp[num] ++;
//    }
//    int ans = 1;
//    for (auto &it : mp) {
//        if (it.second >= n - k) {
//            ans = max(ans, it.second);
//        }
//    }
//
//    return ans;
//}


int longestEqualSubarray(vector<int>& nums, int k) {

    //内存,时间O(kn);爆内存
    int n = nums.size();
    //第一行，最后一列为辅助行
    //len, cur_k
    vector<vector<int>> dp(n + 1, vector<int>(k + 2, 0));
    nums.insert(nums.begin(), nums[0]);
    int ans = 1;
    
    //vector<int> nums = {1,1,2,2,1,1};

    for (int i = 1; i <= n; ++ i) {
        if (nums[i] == nums[i - 1]) {
            //和前一个数字相等，直接继承并加一
            for (int j = 0; j <= k; ++ j) {
                dp[i][j] = dp[i - 1][j] + 1;
                ans = max(ans, dp[i][j]);
            }
        } else {
            //j为消耗个数
            for (int j = 0; j <= k; ++ j) {
                //寻找左侧第一个和他相等的，若没有，则置于，表示消耗清除次数，并自身做尾数
                //找到相等后，思路同上
                if (i - j - 1 >= 0 && nums[i] != nums[i - j - 1]) {
                    dp[i][k - j] = 1;
                } else if (i - j - 1 >= 0 && nums[i] == nums[i - j - 1]) {
                    for (int z = k - j; z >= 0; -- z) {
                        dp[i][z] = dp[i - j - 1][z + j] + 1;
                        ans = max(ans, dp[i][z]);
                    }
                    break;
                }
            }
        }
    }
    //for (auto &it : dp) {
    //    for (auto &num : it) {
    //        cout << num << "; ";
    //    }
    //    cout << endl;
    //}
    return ans;
}

int longestEqualSubarray(vector<int>& nums, int k) {
    //内存O(n + k) 时间O(n)
    int ans = 1;
    int n = nums.size();
    unordered_map<int, vector<int>>mp;
    for (int i = 0; i < n; ++ i) {
        mp[nums[i]].push_back(i);
    }
    for (auto &it : mp) {
        sort(it.second.begin(), it.second.end());
        int m = it.second.size();
        int left = 0, right = 0;
        while (right < m) {
            int tmp = it.second[right] - it.second[left] + 1;
            int cnt = right - left + 1;
            if (tmp - cnt > k) {
                ++ left;
            } else {
                ans = max(ans, cnt);
                ++ right;
            }
        }
    }

    return ans;
}

//优化
pos[r] - pos[l] - (r - l) --> (pos[r] - r) - (pos[l] - l) //如此，记录表里的值就要更新格式

int longestEqualSubarray(vector<int>& nums, int k) {
    //内存O(n + k) 时间O(n)
    int ans = 1;
    int n = nums.size();
    vector<vector<int>> pos_lists(n + 1);
    for (int i = 0; i < n; ++ i) {
        pos_lists[nums[i]].push_back(i - pos_lists[nums[i]].size());
    }
    for (auto &pos : pos_lists) {
        int left = 0;
        for (int right = 0; right < pos.size(); ++ right) {
            if (pos[right] - pos[left] > k) {
                ++ left;
            } else {
                ans = max(ans, right - left + 1);
            }
        }
    }

    return ans;
}