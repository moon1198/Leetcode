#include <vector>
#include <queue>
#include <algorithm>
#include "TreeNode"

using namespace std;

//计算深度
int recur110_1(TreeNode* root) {
    if (root == nullptr) return 0;
    int left = recur110_1(root->left);
    int right = recur110_1(root->right);
    return max(left, right) + 1;
}

bool recur110_0(TreeNode* root) {
    if (root == nullptr) return true;
    int left = recur110_1(root->left);
    int right = recur110_1(root->right);
    if (abs(left - right) > 1) return false;
    return recur110_0(root->left) && recur110_0(root->right);
}
bool solution110_0(TreeNode* root) {
    return recur110_0(root);
}

int recur110_2(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    int left = recur110_2(root->left);
    if (left == -1) return -1;
    int right = recur110_2(root->right);
    if (right == -1) return -1;
    if (abs(left - right) > 1) return -1;
    return max(left, right) + 1;
}
bool solution110_1(TreeNode* root) {
    return recur110_2(root) == -1 ? false : true;
}