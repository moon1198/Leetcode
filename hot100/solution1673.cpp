#include <bits/stdc++.h>
using namespace std;

//都是一次遍历，但条件判别位置放置不同

vector<int> mostCompetitive(vector<int>& nums, int k) {
    int n = nums.size();
    //前入后出
    deque<int> stk;
    int i = 0;
    vector<int> ans;
    for (; k > 0; --k) {
        // cout << "i = " << i << endl;
        for (;i < n - k + 1; ++i) {
            while (!stk.empty() && nums[i] < nums[stk.front()]) {
                stk.pop_front();
            } 
            stk.push_front(i);
        }
        ans.push_back(nums[stk.back()]);
        stk.pop_back();
    }

    return ans;
}

vector<int> mostCompetitive(vector<int>& nums, int k) {
    int n = nums.size();
    // 前入后出
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        while (!ans.empty() && nums[i] < ans.back() &&
               ans.size() + n - i > k) {
            ans.pop_back();
        }
        if (ans.size() < k) {
            ans.push_back(nums[i]);
        }
    }
    return ans;
}