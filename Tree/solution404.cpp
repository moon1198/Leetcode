#include <vector>
#include <queue>
#include <algorithm>
#include "TreeNode"

using namespace std;

int recur404_0(TreeNode* root, bool isLeft) {
    if (!(root->left || root->right) && isLeft) return root->val;
    int left = 0, right = 0;
    if (root->left) left = recur404_0(root->left, true);
    if (root->right) right = recur404_0(root->right, false);
    return left + right;
}

int solution404_0(TreeNode* root) {
    if (root == nullptr) return 0;
    return recur404_0(root, false);
}