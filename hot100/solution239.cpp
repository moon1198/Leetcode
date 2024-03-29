#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    list<int> lst;
    vector<int>ans;
    for (int i = 0; i < k; ++ i) {
        while (!lst.empty() && nums[lst.back()] < nums[i]) {
            lst.pop_back();
        }
        lst.push_back(i);
    }
    ans.push_back(nums[lst.front()]);
    for (int i = k; i < nums.size(); ++ i) {
        while (!lst.empty() && lst.front() <= i - k) {
            lst.pop_front();
        }

        while (!lst.empty() && nums[lst.back()] < nums[i]) {
            lst.pop_back();
        }
        lst.push_back(i);
        ans.push_back(nums[lst.front()]);
    }
    return ans;
}
