#include <stack>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans(nums1.size(), -1);
    //val, index
    map<int, int> mp;
    stack<int>stk;
    for (int i = 0; i < nums1.size(); ++ i) {
        mp[nums1[i]] = i;
    }

    for (int i = 0; i < nums2.size(); ++ i) {
        
        while (!stk.empty() && nums2[i] > nums2[stk.top()]) {
            auto it = mp.find(nums2[stk.top()]);
            if (it != mp.end()) {
                ans[it->second] = nums2[i];
            }
            stk.pop();
        }
        stk.push(i);
    }
    return ans;
}