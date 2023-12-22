#include <vector>
#include <queue>
#include <algorithm>
#include "TreeNode"

TreeNode *solution701_0(TreeNode *root, int val) {
    if (root == nullptr) {
        root = new TreeNode(val);
        return root;
    }
    TreeNode *cur = root;

    while(cur != nullptr) {
        TreeNode *tmp;
        if (val > cur->val) {
            tmp = cur->right;
            if (tmp == nullptr) cur->right = new TreeNode(val);
            cur = tmp;
        }else if(val < cur->val) {
            tmp = cur->left;
            if (tmp == nullptr) cur->left = new TreeNode(val);
            cur = tmp;
        }else{
            return nullptr;
        }
    }
    return root;
}