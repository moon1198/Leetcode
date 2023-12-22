#include <vector>
#include <queue>
#include <algorithm>
#include <stdexcept>
#include "TreeNode"
using namespace std;

//creat the tree by dichotomy, at each node,
//divide the data into two equal groups
TreeNode * recur108_0(vector<int> &nums, int l, int r) {
    if (r <= l) return nullptr;
    int index = (l + r ) / 2;
    TreeNode *tmp_node = new TreeNode(nums[index]);
    tmp_node->left = recur108_0(nums, l, index);
    tmp_node->right = recur108_0(nums, index + 1, r);
    return tmp_node;
}
TreeNode *solution108_0(vector<int> &nums) {
    int len = nums.size();
    return recur108_0(nums, 0, len);
}