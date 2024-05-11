#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
    //所谓置换，必然是一大一小两位数进行调换，若要是下一个更大，必然增大满足条件的最小位
    //最小位之前的不动，由置换位右侧刚刚大于置换位的值进行swap
    //然后将置换位右侧所有，进行增序排序
    stack<int> stk;
    int i = 0;
    for (i = nums.size() - 1; i >= 0; -- i) {
        if (stk.empty()) {
            stk.push(i);
            continue;
        }
        if (nums[i] >= nums[stk.top()]) {
            stk.push(i);
        } else {
            int tmp = -1;
            while (!stk.empty() && nums[i] < nums[stk.top()]) {
                tmp = stk.top();
                stk.pop();
            }
            swap(nums[tmp], nums[i]);
            break;
        }
    }
    sort(nums.begin() + i + 1, nums.end(), [](int &a, int &b){return a < b;});
}