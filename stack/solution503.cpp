#include <stack>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    vector<int> ans(nums.size(), -1);
    stack<int> stk;
    for (int i = 0; i < nums.size() * 2; ++ i) {
        while (!stk.empty() && nums[i % nums.size()] > nums[stk.top()]) {
            ans[stk.top()] = nums[i % nums.size()];
            stk.pop();
        }
        stk.push(i % nums.size());
    }
    return ans;
}