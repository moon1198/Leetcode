#include <vector>
#include <queue>
#include <algorithm>
#include "TreeNode"

using namespace std;

bool recur112_0(TreeNode* root, int val, int target) {
    if (!(root->left || root->right)) {
        if (val == target) return true;
    }
    bool left = false, right = false;
    if (root->left) left = recur112_0(root->left, val + root->left->val, target);
    if (root->right) right = recur112_0(root->right, val + root->right->val, target);
    return left || right;
}
bool solution112_0(TreeNode* root, int targetSum) {
    if (root == nullptr) return false;
    return recur112_0(root, root->val, targetSum);
}



bool recur112_1(TreeNode* root, int count) {
    if (!root) return false;
    if (!(root->left || root->right) && count == root->val) return true;
    return recur112_1(root->left, count - root->val) || recur112_1(root->right, count - root->val);
}
bool solution112_1(TreeNode* root, int targetSum) {
    if (root == nullptr) return false;
    return recur112_1(root, targetSum);
}