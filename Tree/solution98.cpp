#include <vector>
#include <queue>
#include <algorithm>
#include "TreeNode"

using namespace std;

bool recur98_0(TreeNode* root) {
    if (root == nullptr) return true;
    if (!(recur98_0(root->left) && recur98_0(root->right))) return false;
    TreeNode* tmp = root->right;
    int min = INT_MAX, max = INT_MIN;
    while (tmp != nullptr) {
        min = tmp->val;
        tmp = tmp->left;
        if (min <= root->val) return false;
    }

    tmp = root->left;
    while (tmp != nullptr) {
        max = tmp->val;
        tmp = tmp->right;
        if (max >= root->val) return false;
    }
    return true;
}


bool solution98_0(TreeNode* root) {
    return recur98_0(root);
}