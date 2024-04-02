#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

TreeNode *recur(vector<int> &nums, int begin, int end) {
    if (begin > end) {
        return nullptr;
    }
    int mid = (begin + end) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    //if (begin == end) {
    //    return root;
    //}
    root->left = recur(nums, begin, mid - 1);
    root->right = recur(nums, mid + 1, end);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    int len = nums.size();
    return recur(nums, 0, len - 1);
}