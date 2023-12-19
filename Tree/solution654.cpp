#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include "TreeNode"

using namespace std;

TreeNode* recur654_0(vector<int>& nums, int bg, int ed) {
    int maxVal = nums[bg];
    TreeNode* left = nullptr, * right = nullptr;
    int maxIndex = 0, len = ed - bg;
    if (len == 1) {
        return new TreeNode(maxVal, left, right);
    }

    for (int i = 0; i < len; ++ i) {
        if (maxVal < nums[bg + i]) {
            maxIndex = i;
            maxVal = nums[bg + i];
        }
    }
    if (maxIndex) left = recur654_0(nums, bg, bg + maxIndex);
    if (ed - bg - maxIndex - 1) right = recur654_0(nums, bg + maxIndex + 1, ed);
    return new TreeNode(maxVal, left, right);
}
TreeNode* solution654_0(vector<int>& nums) {
    if (nums.empty()) return nullptr;
    return recur654_0(nums, 0, nums.size());
}