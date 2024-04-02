#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

bool recur (TreeNode *root) {
    if (root == nullptr) return true;
    if (!(recur(root->left) && recur(root->right))) return false;
    int min_val = INT_MAX; int max_val = INT_MIN;
    TreeNode *tmp = root->left;
    while (tmp) {
        max_val = max(max_val, tmp->val);
        tmp = tmp->right;
        if (root->val <= max_val) return false;
    }
    tmp = root->right;
    while (tmp) {
        min_val = min(min_val, tmp->val);
        tmp = tmp->left;
        if (root->val >= min_val) return false;
    }
    return true;
}

bool recur0(TreeNode *root, long min, long max) {
    //每次递归附带数据为，当前节点以及该节点的允许数据范围
    if (!root) return true;
    if (root->val >= max || root->val <= min) return false;
    return recur0(root->left, min, root->val) && recur0(root->right, root->val, max);
}

bool isValidBST(TreeNode* root) {
    //左子树最大值小于根节点，右子树最小值大于根节点
    //而不是简单的左右子节点和根节点的大小比对关系
    // return recur(root);
    return recur0(root, LONG_MIN, LONG_MAX);
}