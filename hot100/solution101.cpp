#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

bool check(TreeNode *root1, TreeNode *root2) {
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    } else if (root1 == nullptr || root2 == nullptr) {
        return false;
    }

    if (root1->val != root2->val) {
        return false;
    }
    bool left = check(root1->left, root2->right);
    bool right = check(root1->right, root2->left);
    return left && right;
}
bool isSymmetric(TreeNode* root) {
    return check(root->left, root->right);
}